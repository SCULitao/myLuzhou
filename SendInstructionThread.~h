//---------------------------------------------------------------------------

#ifndef SendInstructionThreadH
#define SendInstructionThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class SendInstructionThread : public TThread
{            
private:
protected:
    void __fastcall Execute();
public:
    __fastcall SendInstructionThread(bool CreateSuspended);
    void __fastcall ShutdownTimer();
    void __fastcall replyData();
};
//---------------------------------------------------------------------------
#endif
