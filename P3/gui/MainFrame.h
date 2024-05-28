#pragma once
#include <wx/wx.h>
#include "board.h"
#include "MinMax.h"
#include <wx/spinctrl.h>


class MainFrame: public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();
	void BindEventsHandlers();
	void OnStartButtonClicked(wxCommandEvent& evt);
	void OnSwitchButtonClicked(wxCommandEvent& evt);
	void OnExitButtonClicked(wxCommandEvent& evt);
	void OnBoardSizeChanged(wxCommandEvent& evt);
	void OnMenuButtonClicked(wxCommandEvent& evt);
	void OnRestartButtonClicked(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
	void Game();
	void restartGame();
	void AiTurn();


	char player = 'X', AI = 'O', currentTurn = 'X', whoWon = 'E';
	int size = 3, roundNumber = 0;
	bool end = false;
	std::vector<wxButton*> Buttons;
	board ttt;

	// Menu g³ówne
	wxPanel* panel;
	wxStaticText* headlineText;
	wxStaticText* info;
	wxButton* startButton;
	wxButton* exitButton;
	wxButton* switchButton;
	wxSpinCtrl* boardSize;

	// Gra
	wxButton* menuButton;
	wxButton* restartButton;
	wxStaticText* turn;
};

