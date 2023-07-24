//---------------------------------------------------------------------------

#ifndef LoginRegistrationFormH
#define LoginRegistrationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TmyLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *UserName;
	TEdit *UserNameEdit;
	TLabel *Password;
	TEdit *PassEdit;
	TButton *LoginButton;
	TLabel *messageLabel;
	void __fastcall LoginButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyLogin *myLogin;
//---------------------------------------------------------------------------
#endif
