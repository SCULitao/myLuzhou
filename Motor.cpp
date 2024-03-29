#include <vcl.h>
#pragma hdrstop
#include "Motor.h"
#pragma package(smart_init)
#pragma link "iAngularGauge"
#include"Unit1.h"
extern int currentMotorIndex;
Motor::Motor(TRzPanel* panelInFrame){

    panel=new TRzPanel(panelInFrame);
    numLabel=new TRzLabel(panel);
    numShow=new TRzLabel(panel);
    nameLabel=new TRzLabel(panel);
    nameShow=new TRzLabel(panel);
    frequencySpeedRatioValue=new TRzLabel(panel);
    settingValueLabel=new TRzLabel(panel);
    settingValueShow=new TRzLabel(panel);
    SpeedLabel=new TRzLabel(panel);
    dometer= new TiOdometer(panel);
    busSpeedRatioValue=new TRzLabel(panel);
    PID=new TRzLabel(panel);
    panel->Parent=panelInFrame;
    numLabel->Parent=panel;
    numShow->Parent=panel;
    nameLabel->Parent=panel;
    nameShow->Parent=panel;
    SpeedLabel->Parent=panel;
    dometer->Parent=panel;
    settingValueLabel->Parent=panel;
    settingValueShow->Parent=panel;
    frequencySpeedRatioValue->Parent=panel;
    busSpeedRatioValue->Parent=panel;
    PID->Parent=panel;
    
    panel->Align=alCustom;
    panel->Top=385;
    panel->Width=123;
    panel->Height=120;
    panel->Enabled=true;
    panel->Visible=true;
    panel->BorderWidth=4;
    panel->OnClick=ClickedMotor;
    panel->Color=clMedGray;
    panel->BorderWidth=5;

    numLabel->Top=16;
    numLabel->Left=8;
    numLabel->Width=36;
    numLabel->Height=13;
    numLabel->Caption="编号：";
    numLabel->Enabled=true;
    numLabel->Visible=true;

    numShow->Top=16;
    numShow->Left=48;
    numShow->AutoSize=false;
    numShow->Width=50;
    numShow->Height=13;
    numShow->Caption="001";
    numShow->Enabled=true;
    numShow->Visible=true;

    nameLabel->Top=32;
    nameLabel->Left=8;
    nameLabel->Width=36;
    nameLabel->Height=13;
    nameLabel->Caption="名称：";
    nameLabel->Enabled=true;
    nameLabel->Visible=true;

    nameShow->Top=32;
    nameShow->Left=40;
    nameShow->AutoSize=false;
    nameShow->Width=50;
    nameShow->Height=13;
    if(nameShow->Caption=="")
        nameShow->Caption="新电机";
    nameShow->TextStyle=tsRaised;
    nameShow->Visible=true;
    nameShow->Enabled=true;


    settingValueLabel->Top=48;
    settingValueLabel->Left=8;
    settingValueLabel->AutoSize=false;
    settingValueLabel->Width=48;
    settingValueLabel->Height=13;
    settingValueLabel->Caption="设定值：";
    settingValueLabel->Enabled=true;
    settingValueLabel->Visible=true;

    settingValueShow->Top=48;
    settingValueShow->Left=56;
    settingValueShow->Height=13;
    settingValueShow->AutoSize=false;
    settingValueShow->Width=55;
    if(settingValueShow->Caption=="")
        settingValueShow->Caption="暂无";
    settingValueShow->Enabled=true;
    settingValueShow->Visible=true;

    SpeedLabel->Top=70;
    SpeedLabel->Left=8;
    SpeedLabel->AutoSize=false;
    SpeedLabel->Width=48;
    SpeedLabel->Height=13;
    SpeedLabel->Caption="实际值:";
    SpeedLabel->Enabled=true;
    SpeedLabel->Visible=true;

    dometer->Top=66;
    dometer->Left=56;
    dometer->AutoSize=false;
    dometer->Width=57;
    dometer->Height=20;
    dometer->DigitsCount=4;
    dometer->TenthsDigitCount=2;
    if(!dometer->Value)
        dometer->Value=1;
    dometer->Enabled=true;
    dometer->Visible=true;
    dometer->BorderMargin=1;

    frequencySpeedRatioValue->Visible=false;
    if(frequencySpeedRatioValue->Caption==""){
        frequencySpeedRatioValue->Caption=100;
    }
    busSpeedRatioValue->Visible=false;
    if(busSpeedRatioValue->Caption==""){
        busSpeedRatioValue->Caption=1;
    }
    PID->Visible=false;
    if(PID->Caption==""){
        PID->Caption=-1;
    }
}

Motor::~Motor()
{
    delete (numLabel);
    delete(numShow);
    delete(nameLabel);
    delete(nameShow);
    delete(SpeedLabel);
    delete(dometer);
    delete(settingValueLabel);
    delete(settingValueShow);
    delete(frequencySpeedRatioValue);
    delete(PID);
    delete(busSpeedRatioValue);
    delete(panel);


}

void __fastcall Motor::ClickedMotor(TObject *Sender){
    AnsiString s=this->panel->Name;
    if(s.Length()==7){
        currentMotorIndex=s[7]-'0';
    }else{
        currentMotorIndex=(s[7]-'0')*10+(s[8]-'0');
    }
}
