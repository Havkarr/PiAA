#include "MainFrame.h"
#include <wx/wx.h>
#include "board.h"
#include "MinMax.h"
#include <vector>
#include <math.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	SetBackgroundColour(wxColor(67,75,79));
	CreateControls();
	BindEventsHandlers();
}


void MainFrame::CreateControls()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	headlineText = new wxStaticText(panel, wxID_ANY, "Kó³ko i krzy¿yk!",
		wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineText->SetFont(headlineFont);

	info = new wxStaticText(panel, wxID_ANY, "Wybierz rozmiar pola do gry:",
		wxPoint(0, 100), wxSize(600, -1), wxALIGN_CENTER_HORIZONTAL);
	info->SetFont(mainFont);
	
	wxString switchText = wxString::Format("Chce graæ %c", player);

	startButton = new wxButton(panel, wxID_ANY, "Start.", wxPoint(350, 180), wxSize(-1, 35));
	switchButton = new wxButton(panel, wxID_ANY, switchText, wxPoint(325, 240), wxSize(-1, 35));
	exitButton = new wxButton(panel, wxID_ANY, "Wyjœcie", wxPoint(350, 300), wxSize(-1, 35));

	startButton->SetBackgroundColour(*wxLIGHT_GREY);
	switchButton->SetBackgroundColour(*wxLIGHT_GREY);
	exitButton->SetBackgroundColour(*wxLIGHT_GREY);
	
	boardSize = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(470, 95), wxSize(100, -1));
	boardSize->SetValue(size);

	menuButton = new wxButton(panel, wxID_ANY, "Menu", wxPoint(650, 180), wxSize(-1, 35));
	restartButton = new wxButton(panel, wxID_ANY, "Od nowa?", wxPoint(650, 240), wxSize(-1, 35));
	turn = new wxStaticText(panel, wxID_ANY, "Gotowy do gry?",
		wxPoint(0, 100), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);

	menuButton->SetBackgroundColour(*wxLIGHT_GREY);
	restartButton->SetBackgroundColour(*wxLIGHT_GREY);

	menuButton->Hide();
	restartButton->Hide();
	turn->Hide();
}

void MainFrame::BindEventsHandlers()
{
	startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
	switchButton->Bind(wxEVT_BUTTON, &MainFrame::OnSwitchButtonClicked, this);
	exitButton->Bind(wxEVT_BUTTON, &MainFrame::OnExitButtonClicked, this);
	boardSize->Bind(wxEVT_SPINCTRL, &MainFrame::OnBoardSizeChanged, this);
	menuButton->Bind(wxEVT_BUTTON, &MainFrame::OnMenuButtonClicked, this);
	restartButton->Bind(wxEVT_BUTTON, &MainFrame::OnRestartButtonClicked, this);
}

void MainFrame::OnStartButtonClicked(wxCommandEvent& evt)
{
	startButton->Hide();
	switchButton->Hide();
	exitButton->Hide();
	boardSize->Hide();
	info->Hide();

	restartButton->Show();
	menuButton->Show();
	turn->Show();

	Game();
}

void MainFrame::OnSwitchButtonClicked(wxCommandEvent& evt)
{
	char tmp = AI;
	AI = player;
	player = tmp;
	wxString switchText = wxString::Format("Chce graæ %c", player);
	switchButton->SetLabel(switchText);
}

void MainFrame::OnExitButtonClicked(wxCommandEvent& evt)
{
	Close(true);
}

void MainFrame::OnBoardSizeChanged(wxCommandEvent& evt)
{
	size = evt.GetInt();
}

void MainFrame::Game()
{
	ttt.changeSize(size);
	int ID = 0;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			wxButton* tmp = new wxButton(panel, ID++, "", wxPoint(100 + j * 100, 50 + i * 100), wxSize(90, 90));
			tmp->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
			Buttons.push_back(tmp);
		}
	}

	if (currentTurn == player) // Ruch gracza
	{
		wxString playerMove = wxString::Format("Teraz gra: %c", player);
		turn->SetLabel(playerMove);
	}
	else // Ruch komputera
	{
		wxString aiMove = wxString::Format("Teraz gra: %c", AI);
		turn->SetLabel(aiMove);
		AiTurn();
	}
}

void MainFrame::restartGame()
{
	// Wyczyœæ plansze w GUI
	for (int i = 0; i < Buttons.size(); i++)
	{
		Buttons[i]->SetLabel("");
	}
	roundNumber = 0;

	// Wyczyœæ plansze w programie
	for (int j = 1; j <= ttt.getSize(); j++)
	{
		for (int k = 1; k <= ttt.getSize(); k++)
		{
			ttt.removeElement(j, k);
		}
	}
	whoWon = 'E';
	end = false;
}

void MainFrame::AiTurn()
{
	whoWon = ttt.checkIfEnd();
	if (whoWon == 'O')
	{
		turn->SetLabel("Wygra³o O!");
		end = true;
		return;
	}
	else if (whoWon == 'X')
	{
		turn->SetLabel("Wygra³ X!");
		end = true;
		return;
	}

	if (roundNumber == size * size)
	{
		turn->SetLabel("Mamy remis!");
		end = true;
		return;
	}

	wxString aiMove = wxString::Format("Teraz gra: %c", AI);
	turn->SetLabel(aiMove);

	position nextPosition = nextMove(ttt, AI); // Oblicz za pomoca min-max nastepny ruch
	ttt.placeChar(nextPosition.row, nextPosition.col, AI);

	aiMove = wxString::Format("%c", AI);
	Buttons[3 * (nextPosition.row - 1) + (nextPosition.col - 1)]->SetLabel(aiMove);

	currentTurn = player;
	++roundNumber;

	whoWon = ttt.checkIfEnd();
	if (whoWon == 'O')
	{
		turn->SetLabel("Wygra³o O!");
		end = true;
		return;
	}
	else if (whoWon == 'X')
	{
		turn->SetLabel("Wygra³ X!");
		end = true;
		return;
	}

	if (roundNumber == size * size)
	{
		turn->SetLabel("Mamy remis!");
		end = true;
		return;
	}

	wxString playerMove = wxString::Format("Teraz gra: %c", player);
	turn->SetLabel(playerMove);
}

void MainFrame::OnMenuButtonClicked(wxCommandEvent& evt)
{
	restartButton->Hide();
	menuButton->Hide();
	turn->Hide();

	startButton->Show();
	switchButton->Show();
	exitButton->Show();
	boardSize->Show();
	info->Show();

	for (int i = 0; i < Buttons.size(); i++)
	{
		Buttons[i]->Destroy();
	}
	Buttons.clear();
	restartGame();
}

void MainFrame::OnRestartButtonClicked(wxCommandEvent& evt)
{
	restartGame();
	Game();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt)
{
	int buttonId = evt.GetId();
	if (ttt.placeChar(1+floor(buttonId/size),1+buttonId%size ,currentTurn) && currentTurn == player && end==false)
	{
		wxString pick = wxString::Format("%c", currentTurn);
		Buttons[buttonId]->SetLabel(pick);
		currentTurn = AI;
		++roundNumber;
		AiTurn();
	}
}
