//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SendInstructionThread.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall SendInstructionThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall SendInstructionThread::SendInstructionThread(bool CreateSuspended)
    : TThread(CreateSuspended)
{

}
//---------------------------------------------------------------------------
void __fastcall SendInstructionThread::Execute()
{
    //---- Place thread code here ----
    if(MainForm->ClientSocket1->Socket->Connected&&!this->Terminated){
        for(int i=0;i<motorCount;i++){
            if(sendQueue->Count()!=0){
                Instruction* ins=(Instruction*)sendQueue->Pop();
                MainForm->ClientSocket1->Socket->SendBuf(ins->getData(),26);
                //Synchronize(replyData);
                //控制0.1s的延迟
                LARGE_INTEGER litmp;
                LONGLONG QPart1,QPart2;
                double dfMinus,dfFreq,dfTim;
                QueryPerformanceFrequency(&litmp);
                dfFreq = (double)litmp.QuadPart;// 获得计数器的时钟频率
                QueryPerformanceCounter(&litmp);
                QPart1 = litmp.QuadPart;// 获得初始值
                do
                {
                    QueryPerformanceCounter(&litmp);
                    QPart2 = litmp.QuadPart;//获得中止值
                    dfMinus = (double)(QPart2-QPart1);
                    dfTim = dfMinus / dfFreq;// 获得对应的时间值，单位为秒
                }while(dfTim<0.1);
                
            }
        }
    }else{
        Synchronize(ShutdownTimer);
        MainForm->ClientSocket1->Socket->Close();
        MainForm->ClientSocket1->Close();
    }
}
void __fastcall  SendInstructionThread::ShutdownTimer(){
    MainForm->Timer1->Enabled=false;
}

void __fastcall SendInstructionThread::replyData(){
    while(MainForm->ClientSocket1->Socket->ReceiveLength()>0){
        continue;
    }
}
