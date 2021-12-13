//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CandleCh"
#pragma link "ErrorBar"
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TForm1 *Form1;


bool num_ch_open = false;
AnsiString DFile;    //текущий файл
AnsiString TableLentaFile;    //текущий файл
int Kurr_Ptr = 0;    //текущий указатель в файле
int Len_Block = 4096; //размер блока данных читаемого из файла
int Len_Data = 0; //размер блока данных читаемого из файла
int Len_Data_Read = 0;
int Len_Data_View = LEN_VIEW_DEF; //размер блока данных читаемого из файла
int Data_View_Start = 0;
int Len_File_Data = 0;
int Len_Obr_Data = LEN_VIEW_DEF;
int Start_Obr_Data = 0;
int LenF1, LenF2;
int BlockView = 1024;
int BlockZoomView = 1024;
int OldView;

float data_buf_prep[2][N_RCV_MAX]; //буфер готовых данных для обработки
complex<float> data_garm[N_MAX_GARM][MAX_H]; //буфер готовых данных для обработки
float data_garm_abs[N_MAX_GARM][MAX_H]; //буфер готовых данных для обработки
float data_garm_usr[N_MAX_GARM][MAX_H_USR]; //буфер готовых данных усредненных гармоник
float garm_amax[MAX_H];
float garm_gmax[MAX_H];
int Oboroty_Obr_Tmp[2][MAX_H];
int Oboroty_Obr[2][MAX_H];
int ObErr[MAX_H_ERR];
int NumErrD = 0;
int ObErrDop[MAX_H_ERR];
int ObErrAvto[MAX_H_ERR];
int ObErrDopS[MAX_H_ERR];
int NumErrDop = 0;
int OborUsr = 0;
int hei_buf[MAX_H];
int time_buf[MAX_H];
float Postoyanka_Ob[MAX_H];
int Nreductor = 0;

float time_buf_dv[MAX_H];
float time_buf_dv2[MAX_H];
float time_buf_sort[2][MAX_H];

float data_usr_obor[MAX_H];

float TableLenta[MAX_METOK_LENTA];
int TableNumMetok = 0;
bool FlagTableLenta = false;

int NumHei = 0;
int NumHeiObr = 0;
float MaxTimeOb;
float MinTimeOb;
float MeanTimeOb;
float MaxObor;
float MinObor;
float GarmMaxAbs = 0;
int OborDataView = 0;
int Chart_Max[2] = {2000,2000};
int Chart_Min[2] = {-2000,-2000};

float Max[2];
float Min[2];
float Mean[2];
float Porog[2];
float Fd = 3472;
float Tfd;
bool Fl_OK = false;
bool Fl_Zoomed = false;
complex<float> fft_buf[16];

int NS_Post = 128;
bool Fl_Syem = false;
bool Cnt_Syem = false;

int NOborFix = 1;
int TactDv = 4;
float KRed = 1.0;
int NumSampleOborEnc;
bool SelDelOb = false;
bool FL_ErrDopOb = false;
//----------ДЛЯ ЭНКОДЕРА ----------------------------------------------------
#define LENWINP 21
long NumSampleEnc;
int Len_Enc_Data = 0;
int StrobEnc = 0;
unsigned Ncntrd = 0;
float data_buf_encod[100000];
float EncPorog[100000];
float EncPorogT[N_RCV_MAX];
int NumEncView = 100000;
float PorogEnc = 1000.0;
double FdEnc = 320000.0;
double DtEnc = 1/320000.0;
int EncNumMetok = 360;
int EncNumMetokUsred = 612;
float AbsolutEnc = 0.000232544;
float NormEnc = 258000;
int NumObEnc = 0;
int NPorog = 650;
float Koeff = 1.2;
int KDecim = 10;
bool FlAnaliz = false;
bool FlSelect = false; //флаг режима выделения на графике даннных для удаления

int MaxMetok, MinMetok;

int fl_enc_hard  = 0;
//ifstream EData;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
int i;
float d;

if(OpenDialog1->Execute()){ //*
    DFile = OpenDialog1->FileName;

    ListBox1->Clear();
    ListBox2->Clear();

    ListBox1->Items->Add("Открытие файла:");
    ListBox1->Items->Add(DFile);

    Len_Data = 0;
    Len_File_Data = 0;
    Data_View_Start = 0;
    ProgressBar1->Position = 0;
    Form1->Label16->Caption = "Загрузка из файла";

  if(RadioGroup4->ItemIndex==0){ //**           если выбран режим работы с тензодатчиком
      fl_enc_hard = 0;
      if(RadioButton2->Checked){ //***

         if(CheckBox7->Checked==false){ //****
            Len_File_Data = Calc_Len_Data(0);
            ProgressBar1->Max = Len_File_Data/300;
            if(Len_File_Data<=N_RCV_MAX) Len_Data_Read = Len_File_Data;
            else Len_Data_Read = N_RCV_MAX;
            ReadF_Data(0, 0, Len_Data_Read, 0);
         } //****
         else{//****

            if(num_ch_open==false){ //*****
               LenF1 = Calc_Len_Data(0);
               ProgressBar1->Max = LenF1/300;
               ReadF1_Data(0, 0, LenF1);
               ListBox1->Items->Add("Снова нажмите Открыть для файла 2");
               num_ch_open=true;
            }//*****
            else{ //*****
               LenF2 = Calc_Len_Data(0);
               ProgressBar1->Max = LenF2/300;
               ReadF1_Data(0, 1, LenF2);

               if(LenF2==LenF1){ //******
                  Len_File_Data=LenF1;
                  if(Len_File_Data<=N_RCV_MAX) Len_Data_Read = Len_File_Data;
                  else Len_Data_Read = N_RCV_MAX;
                  num_ch_open=false;
               }//******
               else{
                  Len_File_Data = 0;
                  ListBox1->Items->Add("Размеры файлов не совпадают");
               }//******
             }//*****
          }//****

      } //***

      else{ //***

        if(CheckBox7->Checked==false){ //****
         Len_File_Data = Calc_Len_Data(1);
         ProgressBar1->Max = Len_File_Data/300;
         if(Len_File_Data<=N_RCV_MAX) Len_Data_Read = Len_File_Data;
         else Len_Data_Read = N_RCV_MAX;

         ReadF_Data(0, 0, Len_Data_Read, 1);
        } //****
        else{ //****
          if(num_ch_open==false){ //*****
             LenF1 = Calc_Len_Data(1);
             ProgressBar1->Max = LenF1/300;
             LenF1 = ReadF1_Data(1, 0, LenF1);
             ListBox1->Items->Add("Снова нажмите Открыть для файла 2");
             num_ch_open=true;
          } //*****
          else{ //*****
             LenF2 = Calc_Len_Data(1);
             ProgressBar1->Max = LenF2/300;
             LenF2 = ReadF1_Data(1, 1, LenF2);

             if(LenF2==LenF1){ //******
                Len_File_Data=LenF1;
                if(Len_File_Data>N_RCV_MAX) Len_File_Data = N_RCV_MAX;
                Len_Data = Len_File_Data;
                num_ch_open=false;
             } //******
             else{ //******
                Len_File_Data = 0;
                ListBox1->Items->Add("Размеры файлов не совпадают");
             } //******

           } //*****
        }//****

      }//***

     if(Len_File_Data>0){ //***

       ListBox1->Items->Add("Загрузка данных: завершено");

       Len_Data_View = Len_File_Data;
       LabeledEdit11->Text = "0";
       LabeledEdit13->Text = IntToStr(Len_File_Data);

      //    UpDown2->Max =  (Len_File_Data-Len_Data_View)/Len_Block;
      //    TrackBar1->Max =  (Len_File_Data-Len_Data_View)/Len_Block;

       if(CheckBox1->Checked){//****
         Conv_mV(&data_buf_prep[0][0],  &data_buf_prep[0][0], Len_Data, 0);
         Conv_mV(&data_buf_prep[1][0],  &data_buf_prep[1][0], Len_Data, 1);
       }
       else{ //****
          //Norm_Data_Ob(Len_Data);
          //norm_data(&data_buf_prep[0][0],  &data_buf_prep[0][0], Len_Data, 0);
          norm_data(&data_buf_prep[1][0],  &data_buf_prep[1][0], Len_Data, 1);
       } //*****

       if(CheckBox3->Checked){ //****
          for(i=0;i<Len_Data;i++) data_buf_prep[1][i] = abs(data_buf_prep[1][i]);
       } //****

       ListBox1->Items->Add("Сэмплов: "+IntToStr(Len_File_Data)+", Время: "+ IntToStr((int)((float)Len_File_Data*(1/Fd)))+" c");
       Calc_Param();
      //  Norm_Data_Ob(Len_Data);
       Paint_Char();

       RadioButton6->Enabled = true;
       RadioButton5->Enabled = true;

       TrackBar1->Max = Len_Data_View/BlockView;
       TrackBar1->Position = 0;
       UpDown2->Position = TrackBar1->Position;
       UpDown2->Max = Len_Data_View/BlockView;
       SpeedButton4->Enabled = true;
       Button16->Enabled = false;

       }//***

  }//**
//======
  else if(RadioGroup4->ItemIndex==1){   //если выбран режим работы с енкодером
          fl_enc_hard = 0;

          ProgressBar1->Max = 30000;
          UpDown2->Position = 0;

          ListBox1->Items->Add("Определение кол-ва сэмплов");
          NumSampleEnc = GetEncNumSampleFile();
          //NumSampleEnc = 50000000;
          ListBox1->Items->Add("Сэмплов: "+IntToStr(NumSampleEnc));
          ListBox1->Items->Add("Время: "+ IntToStr((int)((float)NumSampleEnc*(1/FdEnc)))+" c");
          UpDown2->Max = NumSampleEnc/NumEncView;
          LabeledEdit11->Text =  0;
          LabeledEdit13->Text =  NumSampleEnc;
          ReadEncView(0);
          Button15->Enabled = true;
          SpeedButton4->Enabled = false;
          BitBtn1->Enabled = false;
  }
  else if(RadioGroup4->ItemIndex==2){
          fl_enc_hard = 1;
          ListBox1->Items->Add("Режим аппаратного энкодера");

          ProgressBar1->Max = 30000;
          UpDown2->Position = 0;
          UpDown2->Max = 1;
          LabeledEdit11->Text =  0;
          LabeledEdit13->Text =  0;

          Button15->Enabled = true;
          SpeedButton4->Enabled = false;
          BitBtn1->Enabled = false;
  }

  Button2->Enabled = true;
  NumErrDop = 0;

} //end if(OpenDialog1->Execute())
}

//---------------------------------------------------------------------------
int __fastcall Calc_Len_Data(int type){
char cbuf[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
short d_ch;
int lend = 0;

 if(type==0){
   ifstream inData(DFile.c_str(), ios::in|ios::binary);
   while(!inData.eof()){
      inData.read((char*)&d_ch,sizeof(d_ch));
      lend+=1;
   }
    inData.close();
 }
 else if(type==1){
   ifstream inData(DFile.c_str(), ios::in);
   while(!inData.eof()){
      inData.getline(cbuf, sizeof(cbuf));
      lend+=1;
   }
    inData.close();
 }

 if(Form1->CheckBox7->Checked == false) return lend/2;
 else return lend;

}

int __fastcall ReadF1_Data(int type, int nch, int nd){
int i;
short d_ch;
char cbuf[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int ndata = 0;
char DS = DecimalSeparator;

if(Form1->CheckBox24->Checked) DecimalSeparator = '.';

//nd = 10000;

 if(type==0){

   ifstream inData(DFile.c_str(), ios::in|ios::binary);

   while(ndata!=nd){
      inData.read((char*)&d_ch,sizeof(d_ch));
      data_buf_prep[nch][ndata]=(float)d_ch;
      if(inData.eof()){
          inData.close();
          break;
      }
      if(ndata%300==0) Form1->ProgressBar1->Position+=1;
      ndata++;
   }
   inData.close();

  }
  else if(type==1){

   ifstream inData(DFile.c_str(), ios::in);
   while(ndata!=nd){
      inData.getline(cbuf, sizeof(cbuf));
      data_buf_prep[nch][ndata]=StrToFloat(cbuf);
      if(inData.eof()){
          inData.close();
          break;
      }
      if(ndata==nd){
          inData.close();
          break;
      }
      //if(ndata%300==0) Form1->ProgressBar1->Position+=1;
      ndata++;

   }

  }

DecimalSeparator = DS;

  return ndata;
}

void __fastcall ReadF_Data(int posd, int posf, int nd, int type){
int i;
short d_ch;
char cbuf[8] = {0,0,0,0,0,0,0,0};

 if(type==0){
   ifstream inData(DFile.c_str(), ios::in|ios::binary);
   //inData.seekg(posf);
   while(Len_Data!=nd){
      inData.read((char*)&d_ch,sizeof(d_ch));
      data_buf_prep[0][Len_Data]=(float)d_ch;
      if(inData.eof()){
          inData.close();
          break;
      }
      inData.read((char*)&d_ch,sizeof(d_ch));
      data_buf_prep[1][Len_Data]=(float)d_ch;
      if(inData.eof()){
          inData.close();
          break;
      }
      if(Len_Data%300==0) Form1->ProgressBar1->Position+=1;
      Len_Data++;
   }
   inData.close();

  }
  else if(type==1){

   ifstream inData(DFile.c_str(), ios::in);
   while(Len_Data!=nd){
      inData.getline(cbuf, sizeof(cbuf));
      data_buf_prep[0][Len_Data]=StrToFloat(cbuf);
      if(inData.eof()){
          inData.close();
          break;
      }
      inData.getline(cbuf, sizeof(cbuf));
      data_buf_prep[1][Len_Data]=StrToFloat(cbuf);
      if(inData.eof()){
          inData.close();
          break;
      }
      if(Len_Data%300==0) Form1->ProgressBar1->Position+=1;
      Len_Data++;
   }

  }

}

void __fastcall Paint_Char(){
   int i;
   float por;
   float Norm_K1;

   Form1->ProgressBar1->Position=0;
   Form1->ProgressBar1->Max = Len_Data_View/500;
   Form1->Label16->Caption = "Отрисовка графика";

   if(Form1->CheckBox4->Checked) por = Mean[1]*StrToFloat(Form1->LabeledEdit1->Text);
   else por = StrToFloat(Form1->LabeledEdit1->Text);

   if(Form1->CheckBox2->Checked) Norm_K1 = Mean[0];
   else Norm_K1 = 0;

   Form1->Chart1->Series[0]->Clear();
   Form1->Chart2->Series[0]->Clear();
   Form1->Chart2->Series[1]->Clear();
/*
   Form1->Chart1->Axes->Left->Minimum = 0;
   Form1->Chart1->Axes->Left->Maximum = 0;
   Form1->Chart1->Axes->Left->Maximum = Chart_Max[0]-Norm_K1;
   Form1->Chart1->Axes->Left->Minimum = Chart_Min[0]-Norm_K1;
*/
   Form1->Chart2->Axes->Left->Minimum = 0;
   Form1->Chart2->Axes->Left->Maximum = 0;
   Form1->Chart2->Axes->Left->Maximum = Chart_Max[1];
   Form1->Chart2->Axes->Left->Minimum = Chart_Min[1];

   Form1->Chart1->Axes->Bottom->Minimum = 0;
   Form1->Chart2->Axes->Bottom->Minimum = 0;

   Form1->Chart1->Axes->Bottom->Maximum = Len_Data_View;
   Form1->Chart2->Axes->Bottom->Maximum = Len_Data_View;
   Norm_K1 = 0;

   for(i=0;i<Len_Data_View;i++){
        Form1->Chart1->Series[0]->AddY((double)data_buf_prep[0][i]-Norm_K1); //
        Form1->Chart2->Series[0]->AddY((double)data_buf_prep[1][i]);
        Form1->Chart2->Series[1]->AddY((double)por);
        if(i%500==0) Form1->ProgressBar1->Position+=1;
   }
   Form1->Chart1->Series[0]->Repaint();
   Form1->Chart2->Series[0]->Repaint();
   Form1->Chart2->Series[1]->Repaint();

}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   int i, ng;

//   Series1->FastPen = true;
//   Series1->AutoRepaint = false;

   Series2->FastPen = true;
   Series2->AutoRepaint = false;

 //  Series3->FastPen = true;
 //  Series3->AutoRepaint = false;

//   Form1->Chart1->Axes->FastCalc = true;
   Form1->Chart2->Axes->FastCalc = true;
   Form1->Chart4->Axes->FastCalc = true;

//   Chart1->Axes->Left->Maximum = Chart_Max[0];
//   Chart1->Axes->Left->Minimum = Chart_Min[0];
   Chart2->Axes->Left->Maximum = Chart_Max[1];
   Chart2->Axes->Left->Minimum = Chart_Min[1];

   Chart1->Axes->Bottom->Maximum = Len_Data_View;
   Chart2->Axes->Bottom->Maximum = Len_Data_View;

   Fd = StrToFloat(LabeledEdit9->Text);
   Tfd = 1/Fd;

   FdEnc = StrToInt(LabeledEdit23->Text);
   DtEnc = 1.0/FdEnc;

   RadioGroup2->ItemIndex = 0;
   RadioGroup3->ItemIndex = 0;
   RadioGroup4->ItemIndex = 0;
   RadioGroup5->ItemIndex = 0;

   int NGarm = StrToInt(Form1->LabeledEdit12->Text);

   CalcNoborFix();
   CheckListBox1->Checked[0]=false;
   for(i=1;i<NGarm;i++){
      CheckListBox1->Checked[i]=true;
   }

//------ чтение настроек из файла ini -------------------------------------------------------
//---------- сохранение настроек в INI файл --------------------------------
   TIniFile *Ini = new TIniFile(".\\settings.ini");

  //--- секция основная панель настроек ---------------------------------------
    RadioGroup4->ItemIndex = StrToInt(Ini->ReadString("Options->Main","Type", "0"));
    LabeledEdit1->Text = Ini->ReadString("Options->Obrabotka","Porog_ob", "100");
    LabeledEdit14->Text = Ini->ReadString("Options->Obrabotka","Okno_usred", "2");
    CheckBox4->Checked = Ini->ReadBool("Options->Obrabotka","Avto_Porog", false);

    RadioGroup5->ItemIndex = StrToInt(Ini->ReadString("Options->Enc","Type", "0"));
    LabeledEdit24->Text = Ini->ReadString("Options->Enc","Porog", "2500");
    CheckBox14->Checked = Ini->ReadBool("Options->Enc","AvtoPorog", 0);
  //---------------------------------------------------------------------------

  //-------- Дополнительно -> Параметры ---------------------------------------
    LabeledEdit10->Text = Ini->ReadString("DopParams->Obrabotka","K_Redukc", "1");
    ComboBox1->Text = Ini->ReadString("DopParams->Obrabotka","Tact_Dv", "4");
    LabeledEdit12->Text = Ini->ReadString("DopParams->Obrabotka","N_Garm", "25");
    LabeledEdit2->Text = Ini->ReadString("DopParams->Obrabotka","Oshibka_ob", "5");
    CheckBox15->Checked = Ini->ReadBool("DopParams->Obrabotka","En_Oshibka_Ob", 0);
    LabeledEdit15->Text = Ini->ReadString("DopParams->Obrabotka","Oshibka_Ampl", "50");
    CheckBox18->Checked = Ini->ReadBool("DopParams->Obrabotka","En_Det_Err_Ob", true);

    LabeledEdit5->Text = Ini->ReadString("DopParams->Data","Norm_k1", "0");
    CheckBox2->Checked = Ini->ReadBool("DopParams->Data","En_Norm_k1_Auto", true);
    LabeledEdit6->Text = Ini->ReadString("DopParams->Data","Norm_k2", "2000");
    CheckBox3->Checked = Ini->ReadBool("DopParams->Data","En_Abs_k2", true);
    CheckBox1->Checked = Ini->ReadBool("DopParams->Data","mV_On", false);
    LabeledEdit16->Text = Ini->ReadString("DopParams->Data","Block_Prokrutki", "1024");
    LabeledEdit19->Text = Ini->ReadString("DopParams->Data","Koef_prokrutki", "1,0");
    LabeledEdit7->Text = Ini->ReadString("DopParams->Data","Razr_ADC", "12");
    LabeledEdit9->Text = Ini->ReadString("DopParams->Data","Fd_ADC", "3472");
    LabeledEdit8->Text = Ini->ReadString("DopParams->Data","Min_ADC", "0");
    LabeledEdit4->Text = Ini->ReadString("DopParams->Data","Max_ADC", "3000");

    LabeledEdit20->Text = Ini->ReadString("DopParams->Encoder","Kol_Metok", "306");
    LabeledEdit24->Text = Ini->ReadString("DopParams->Encoder","Fd_ADC", "320000");
    LabeledEdit21->Text = Ini->ReadString("DopParams->Encoder","ABSOLUT", "0.000232544");
    LabeledEdit22->Text = Ini->ReadString("DopParams->Encoder","Norm", "258000");
    LabeledEdit25->Text = Ini->ReadString("DopParams->Encoder","Err_Ob%", "99");
    LabeledEdit26->Text = Ini->ReadString("DopParams->Encoder","Okno_Poroga", "650");
    LabeledEdit27->Text = Ini->ReadString("DopParams->Encoder","Koef_Poroga", "1.01");
    LabeledEdit28->Text = Ini->ReadString("DopParams->Encoder","Koef_PorogaT", "1.1");

    LabeledEdit29->Text = IntToStr((StrToInt(LabeledEdit20->Text)*2));

    ng = StrToInt(LabeledEdit12->Text);
    for(i=0;i<ng;i++) CheckListBox1->Checked[i] = Ini->ReadBool("ChartGarm",IntToStr(i), 1);

    if(RadioGroup4->ItemIndex>0) PageControl1->TabIndex = 2;
//-------------------------------------------------------------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall Calc_Param(){
int i;
   Max[0] = -100000;
   Max[1] = -100000;
   Min[0] = 100000;
   Min[1] = 100000;
   Mean[0] = 0;
   Mean[1] = 0;

  for(i=0;i<Len_Data_View;i++){

     if(Max[0]<data_buf_prep[0][i]) Max[0] = data_buf_prep[0][i];
     if(Max[1]<data_buf_prep[1][i]) Max[1] = data_buf_prep[1][i];

     if(Min[0]>data_buf_prep[0][i]) Min[0] = data_buf_prep[0][i];
     if(Min[1]>data_buf_prep[1][i]) Min[1] = data_buf_prep[1][i];

     Mean[0]+=data_buf_prep[0][i];
     Mean[1]+=data_buf_prep[1][i];
/*
     d = data_buf_prep[0][i];
     ListBox1->Items->Add(FloatToStr(d));
     d = data_buf_prep[1][i];
     ListBox1->Items->Add(FloatToStr(d));
*/
  }
  Mean[0]=Mean[0]/Len_Data_View;
  Mean[1]=Mean[1]/Len_Data_View;

  Chart_Max[0] = (int)(Max[0]+0.05*Max[0]);
  Chart_Max[1] = (int)(Max[1]+0.05*Max[1]);
  Chart_Min[0] = (int)(Min[0]-0.05*Min[0]);
  Chart_Min[1] = (int)(Min[1]-0.05*Min[1]);

  Form1->ListBox2->Clear();
  Form1->ListBox2->Items->Add("Кол-во сэмплов: "+IntToStr(Len_File_Data));
  Form1->ListBox2->Items->Add("Max_k1: "+FloatToStr(Max[0])+"; "+"Min_k1: "+FloatToStr(Min[0]));
  Form1->ListBox2->Items->Add("Max_k2: "+FloatToStr(Max[1])+"; "+"Min_k2: "+FloatToStr(Min[1]));
  Form1->ListBox2->Items->Add("Mean_k1: "+FloatToStr(Mean[0]));
  Form1->ListBox2->Items->Add("Mean_k2: "+FloatToStr(Mean[1]));
}

void __fastcall norm_data(float* inbuf,  float* out, int n, int nch){
    float normK;
    int i;

    if(nch==0) normK = StrToFloat(Form1->LabeledEdit5->Text);
    else normK = StrToFloat(Form1->LabeledEdit6->Text);

    for(i=0;i<n;i++){
        out[i] = inbuf[i]-normK;
    }
}

void __fastcall Conv_mV(float* inbuf,  float* out, int n, int nch){
    float MaxmV, normK;
    float nADC;
    int rADC;
    int i;
    rADC = StrToInt(Form1->LabeledEdit7->Text);

    MaxmV = StrToFloat(Form1->LabeledEdit4->Text);
    if(nch==0) normK = StrToFloat(Form1->LabeledEdit5->Text);
    else normK = StrToFloat(Form1->LabeledEdit6->Text);
    nADC = 2048.0/MaxmV;
    for(i=0;i<n;i++){
        out[i] = inbuf[i]*nADC-normK;
    }
}


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
  Chart1->BottomAxis->Maximum+=BlockView;
  Chart1->BottomAxis->Minimum+=BlockView;

  Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;

  TrackBar1->Position += BlockView;

//if((Len_Data_View+Len_Block)<=Len_Data) Len_Data_View+=Len_Block;
//    Paint_Char();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  Chart1->BottomAxis->Maximum-=BlockView;
  Chart1->BottomAxis->Minimum-=BlockView;

  Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;

  TrackBar1->Position -= BlockView;
//    if((Len_Data_View-Len_Block)>=Len_Block) Len_Data_View-=Len_Block;
//    Paint_Char();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
  int mx = Chart1->BottomAxis->Maximum;
  int mn = Chart1->BottomAxis->Minimum;

if(RadioGroup4->ItemIndex==1){
    ReadEncView(UpDown2->Position);
    Form1->Label18->Caption = "Позиция: "+IntToStr(UpDown2->Position*NumEncView);
}
else{

  if((Button == btNext) && ((mx+BlockView)<=Len_Data_View)) {
    Chart1->BottomAxis->Maximum+=BlockView;
    Chart1->BottomAxis->Minimum+=BlockView;
  }
  else if((Button == btPrev) && ((mn-BlockView)>=0)){
    Chart1->BottomAxis->Minimum+=-BlockView;
    Chart1->BottomAxis->Maximum+=-BlockView;
  }

  Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;

  TrackBar1->Position = (int)Chart1->BottomAxis->Minimum/BlockView;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
  int mx = Chart1->BottomAxis->Maximum-Chart1->BottomAxis->Minimum;
  int Pos = TrackBar1->Position*BlockView;

  if((Pos+mx)>Chart1->BottomAxis->Maximum){
     Chart1->BottomAxis->Maximum=Pos+mx;
     Chart1->BottomAxis->Minimum=Pos;
     Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
     Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  }
  else{
     Chart1->BottomAxis->Minimum=Pos;
     Chart1->BottomAxis->Maximum=Pos+mx;
     Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
     Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  }

  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;

  UpDown2->Position = TrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit9Enter(TObject *Sender)
{
   Fd = StrToFloat(LabeledEdit9->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  double pX,pY;
 float tob, obm;  
  int i,k;
 int NumO = 0;
 int a,b,delta;

  Series1->GetCursorValues(pX,pY);  // <-- get values under mouse cursor

if((Len_File_Data>BlockZoomView*2) && (CheckBox10->Checked) && (pX>0)){

  Label2->Caption = (int)pX;
  Label4->Caption = ": " + Series1->GetHorizAxis->LabelValue(pX*(1/Fd)) + " с";
  Label5->Caption = Series1->GetVertAxis->LabelValue(pY);

      k = (int)pX;
      //ищем к кокому обороту принадлежит данный отсчет
      if(NumHei>3){
         for(i=0;i<NumHei-1;i++){
           if((hei_buf[i]<k)&&(hei_buf[i+1]>=k)){
              NumO = i;
              break;
           }
         }
         Chart6->Series[0]->Clear();
         a = hei_buf[NumO];
         b = hei_buf[NumO+1];
         delta = b-a;
         
         if(RadioGroup4->ItemIndex==0){
           tob = delta*Tfd;
           obm = 60.0/tob;
           Label20->Caption = "№ Об: " + IntToStr(NumO)+ "; Время Об:" + FloatToStrF(tob, ffGeneral, 4,4)+"; Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Chart1->Hint = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Label22->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
         }
         else{
           tob = time_buf[NumO]/1000.0;
           obm = 60.0/tob;
           Label20->Caption = "№ Об: " + IntToStr(NumO)+ "; Время Об:" + FloatToStrF(tob, ffGeneral, 4,4)+"; Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Chart1->Hint = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Label22->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
         }
         
         for(i=0;i<delta;i++){
           Chart6->Series[0]->AddY(data_buf_prep[0][a+i]);
         }
      }

}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  double pX,pY;
  Series2->GetCursorValues(pX,pY);  // <-- get values under mouse cursor
  Label6->Caption = (int)pX;
  Label7->Caption = ": " + Series2->GetHorizAxis->LabelValue(pX*(1/Fd)) + " с";
  Label8->Caption = Series2->GetVertAxis->LabelValue(pY);
}
//---------------------------------------------------------------------------

int __fastcall Detector_Ob(float* in, int* out, int sn, int n){
    int j;
    int k=0;
    int i=sn;
    int NumS;
    float DS;
    int LenWin = StrToInt(Form1->LabeledEdit3->Text);
    float por =  StrToFloat(Form1->LabeledEdit1->Text);
    bool FDet = false;

    while(i<(n+sn)){

        if(FDet==false){
           if(in[i]>por){
              out[k] = i;
              FDet = true;
              k++;
           }
        }
        else{
           if(in[i]<por){
              FDet = false;
           }
        }
        i++;
        if(k==MAX_H) break;
    }
    return k;

}

void __fastcall Norm_Data_Ob(int nd){
int i,j,n;
int np;
float post;

  np = nd/NS_Post;

  for(i=1;i<np;i++){
     n = hei_buf[i-1];
     post = 0;
     for(j=0;j<NS_Post;j++) post+=data_buf_prep[0][i*NS_Post+j];
     post/=NS_Post;
     for(j=0;j<NS_Post;j++)  data_buf_prep[0][i*NS_Post+j] = data_buf_prep[0][i*NS_Post+j]-post;
  }
  n = nd-np*NS_Post;
  for(j=0;j<n;j++) post+=data_buf_prep[0][np*NS_Post+j];
  post/=n;
  for(j=0;j<n;j++) data_buf_prep[0][np*NS_Post+j]-post;

}


int __fastcall Calc_Param_Ob(){
   int i,j;
   float TimeOb;
   float SumTimeOb = 0;

   TimeOb = ((hei_buf[1]-hei_buf[0])*(1/Fd))*1000.0;
   MaxTimeOb = TimeOb;
   MinTimeOb = TimeOb;
   MeanTimeOb = 0;

   for(i=0;i<NumHei-1;i++){
      TimeOb = ((hei_buf[i+1]-hei_buf[i])*(Tfd))*1000.0;
      time_buf[i] = TimeOb;
      if(MaxTimeOb<TimeOb) MaxTimeOb=TimeOb;
      if(MinTimeOb>TimeOb) MinTimeOb=TimeOb;
      SumTimeOb+=TimeOb;
      //data_buf_prep[1][N_RCV_MAX]
   }
   MeanTimeOb = SumTimeOb/(NumHei-1);
}

//Garmonic analises
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
    int i;
    int NGarm = StrToInt(Form1->LabeledEdit12->Text);
    int tmpi1 = 0;

  if(Len_Data>100){

    CalcNoborFix();
    
    NumErrD =0;
    NumHeiObr = 0;

    if(RadioGroup4->ItemIndex==0){
       if(RadioButton3->Checked) NumHei = Detector_Ob(&data_buf_prep[1][0], hei_buf, 0, Len_Data);
       else NumHei = Detector_Ob(&data_buf_prep[1][0], hei_buf, Data_View_Start, Len_Data_View);
       //    Norm_Data_Ob();
       //    Paint_Char();
       Calc_Param_Ob();
    }

    View_Ob();
    View_ObT();

/*
    for(i=0;i<NumHei;i++){
        ListBox1->Items->Add("N: "+IntToStr(hei_buf[i])+", A: " +FloatToStr(data_buf_prep[0][hei_buf[i]]));
    }
*/
    ListBox1->Items->Add("Кол-во обнаруж. об.: "+IntToStr(NumHei));
    ListBox1->Items->Add("Макс tоб.: "+FloatToStr(MaxTimeOb));
    ListBox1->Items->Add("Мин tоб.: "+FloatToStr(MinTimeOb));
    ListBox1->Items->Add("Средн tоб.: "+FloatToStr(MeanTimeOb));

    if(CheckBox18->Checked) NumErrD = DetErrObor();

    NumHeiObr = Calc_Ob_Reductor();
    
    Calc_Garm();

    CheckListBox1->Clear();

    CheckListBox1->Items->Add("0");
    for(i=1;i<NGarm;i++){
      CheckListBox1->Items->Add(FloatToStr((float)i/(float)(TactDv/2)));
      CheckListBox1->Checked[i] = true;
    }

    //выводим на график косячные обороты
    ViewerrOb();

    //выводим на график метки оборотов
    if(CheckBox19->Checked) ViewMetkiOb();
    else Form1->Chart1->Series[2]->Clear();

    Button16->Enabled = true;
    Button17->Enabled = true;
    Button18->Enabled = true;

   }

//------------- УСРЕДНЕНИЕ -----------------------------

    OborUsr = Calc_Garm_Usr();

    if(RadioGroup2->ItemIndex==1){
       ViewGarm();
    }
    else{
       ViewGarmUsr();
    }

    RadioButton5->Enabled = true;
    CheckBox5->Enabled = true;
    RadioButton5->Checked = true;
    //CheckBox5->Checked = true;

    TrackBar2->Position = 0;
    TrackBar2->Max = OborUsr;
    UpDown3->Position = 0;
    UpDown3->Max = OborUsr;

    if(FL_ErrDopOb) Button2->Enabled = false;
//-----------------------------------------------------------
}
//---------------------------------------------------------------------------

void ViewMetkiOb(){
   int i;
   int k = 0;
   float Mxx, Mnn;
   int Sdvig;
   Form1->Chart1->Series[2]->Clear();
   Mxx = Form1->Chart1->Series[0]->MaxYValue();
   Mnn = Form1->Chart1->Series[0]->MinYValue();

   if(Form1->RadioGroup5->ItemIndex==1) Sdvig = hei_buf[0];
   else Sdvig = 0;

   for(i=0;i<Len_Data;i++){
     if(hei_buf[k]==i){
        Form1->Chart1->Series[2]->AddXY((double)(i),(double)(Mxx));
        //Form1->Chart1->Series[2]->AddXY((double)i,(double)(Mxx*0.5));
        k++;
     }
     else{
        //Form1->Chart1->Series[2]->AddY((double)(Mnn-Mnn*0.05));
     }
   }

if(Form1->RadioGroup4->ItemIndex>0){

   Mxx = Form1->Chart2->Series[0]->MaxYValue();
   Mnn = Form1->Chart2->Series[0]->MinYValue();
   Form1->Chart2->Series[2]->Clear();
   k = 0;
   
   for(i=0;i<Len_Data;i++){
     if(hei_buf[k]==i){
        Form1->Chart2->Series[2]->AddXY((double)(i),(double)(Mxx));
        //Form1->Chart2->Series[2]->AddXY((double)i,(double)(Mxx*0.5));
        k++;
     }
     else{
//        Form1->Chart2->Series[2]->AddY((double)(Mnn));
     }
   }
}

/*
   for(i=0;i<NumHei;i++){
    Form1->Chart1->Series[2]->AddXY((double)(Max[0]*0.6),hei_buf[i]);
    Form1->Chart1->Series[2]->AddXY((double)(Min[0]),hei_buf[i+1]);
   }
*/
}

void ViewerrOb(){
   int i,j;
   int k = 0;
   int errob = 0;
   int errobd = 0;
   bool flo = false;
   bool flod = false;
   int di = 0;
   int cnt_di = 0;
   int tmpi1 = 0;
   int cntdop = 0;
//---------------------------
    Form1->Chart9->Series[1]->Clear();

    for(i=1;i<NumHei-1;i++){
       if(ObErr[tmpi1]==i){
          Form1->Chart9->Series[1]->AddY((double)MaxTimeOb);
          tmpi1++;
       }
       else{
          Form1->Chart9->Series[1]->AddY(0.0);
       }
    }

//--------------------------

    Form1->Chart1->Series[1]->Clear();

    errob = ObErr[0];

/**/for(i=0;i<Len_Data;i++){

       if(flo==false){

          if((i>hei_buf[errob])&&(i<=hei_buf[errob+1])){
             flo = true;
             di = hei_buf[errob+1]-hei_buf[errob];
             cnt_di = 0;
             Form1->Chart1->Series[1]->AddY( (double)(Max[0]+(Max[0]*0.05)) );
          }
          else{

             if(cntdop<NumErrDop){
                for(j=0;j<NumErrDop;j++){
                   if((ObErrDopS[j]<=i) && ((ObErrDopS[j]+50)>i)){
                     Form1->Chart1->Series[1]->AddY( (double)(Max[0]+(Max[0]*0.05)) );
                     cntdop++;
                     flo = true;
                   }
                }
             }
             if(flo==false) Form1->Chart1->Series[1]->AddY( (double)(Min[0]-(Min[0]*0.05)) );
             flo = false;

             // Form1->Chart1->Series[1]->AddY( (double)(Min[0]-(Min[0]*0.05)) );
          }

       }
       else{

          if(cnt_di<di){
             cnt_di++;
             Form1->Chart1->Series[1]->AddY( (double)(Min[0]-(Min[0]*0.05)) );
          }
          else{
             k++;
             if(k<NumErrD){
               flo = false;
               cnt_di = 0;
               errob = ObErr[k];
               Form1->Chart1->Series[1]->AddY( (double)(Max[0]+(Max[0]*0.05)) );
             }
             else{
               break;
             }
          }
       }
/**/}

}

//-------------------------------------------

void __fastcall View_Ob(){
   int i;
   float por;
   float KObor;

   if(Form1->CheckBox8->Checked) Form1->Chart4->Axes->Bottom->Maximum = NumHei;
   else  Form1->Chart4->Axes->Bottom->Maximum = NumHeiObr;

   Form1->Chart4->Series[0]->Clear();
   Form1->Chart4->Series[1]->Clear();

   if(Form1->RadioButton7->Checked){
     if(Form1->CheckBox8->Checked){
      for(i=0;i<NumHei-1;i++) Form1->Chart4->Series[0]->AddY(time_buf[i]);
     }else{
      for(i=0;i<NumHeiObr-1;i++) Form1->Chart4->Series[0]->AddY(time_buf[i]*NOborFix);
     }
   }
   else if(Form1->RadioButton6->Checked){
      for(i=0;i<NumHeiObr-1;i++) Form1->Chart4->Series[1]->AddY(time_buf_dv[i]);
   }
   Form1->Chart4->Series[0]->Repaint();

}

void __fastcall View_ObT(){
   int i;

   Form1->Chart9->Axes->Bottom->Maximum = NumHei;
   Form1->Chart9->Series[0]->Clear();
   Form1->Chart9->Series[1]->Clear();
   
   for(i=0;i<NumHei-1;i++) Form1->Chart9->Series[0]->AddY((double)time_buf[i]);

}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  ListBox1->Clear();
  ListBox2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall Calc_Garm(){
   int i,j,q,k,s;
   float fk;
   float TObor;
   float buf_ob[MAX_LEN_OB]; //буфер данных оборота
   float garm[N_MAX_GARM]; //буфер гармоник для одного оборота
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);  //на сколько раскладывать гармоник
   float Fcentr;
   float PecTime = StrToFloat(Form1->LabeledEdit12->Text); //с каким процентом отклонения от среднего игнорировать оборот
   float GAbs;
   int NGAbs;
   GarmMaxAbs = 0;
   float Postoyanka;
   int MaxObor = 0;
   int MinObor = 0;
   float KSampleObor;
   bool FlError = false;

   Form1->ProgressBar1->Position=0;
   Form1->ProgressBar1->Max = NumHei/NOborFix/10;
   Form1->Label16->Caption = "Вычисление гармоник";

   //NumHeiObr-=2;
   
   for(i=0;i<NumHeiObr;i++){

      s = Oboroty_Obr[0][i];
      k = Oboroty_Obr[1][i];
      fk = (float)k;

      Postoyanka = 0;

      for(j=0;j<k;j++){
           buf_ob[j] = data_buf_prep[0][s+j];  //закидываем оборот в буфер и вычитаем постоянку
           Postoyanka+=data_buf_prep[0][s+j];
      }
      Postoyanka = Postoyanka/fk;
      Postoyanka_Ob[i] = Postoyanka;

      for(j=0;j<k;j++){
         buf_ob[j] = buf_ob[j] - Postoyanka;  //закидываем оборот в буфер и вычитаем постоянку
      }

      NGAbs = 0;
      GarmMaxAbs = 0;

      data_garm[0][i]._M_re = fabs(Postoyanka);
      data_garm[0][i]._M_im = 0;
      data_garm_abs[0][i] = fabs(Postoyanka);

      for(j=1;j<NGarm;j++){

         Fcentr = (float)j*2.0*PI;
         Fcentr = Fcentr/fk; ///(float)NObor);

         data_garm[j][i]._M_re = buf_ob[0]*cos(0);
         data_garm[j][i]._M_im = buf_ob[0]*(-sin(0));

         for(q=1;q<k;q++){
            data_garm[j][i]._M_re += buf_ob[q]*cos(Fcentr*(float)q);
            data_garm[j][i]._M_im += buf_ob[q]*(-sin(Fcentr*(float)q));
         }

         data_garm[j][i]._M_re = data_garm[j][i]._M_re/(fk/2.0);
         data_garm[j][i]._M_im = data_garm[j][i]._M_im/(fk/2.0);//sqrt(k);

         GAbs = abs(data_garm[j][i]);
         data_garm_abs[j][i] = GAbs;

         if(GarmMaxAbs<GAbs){
            GarmMaxAbs = GAbs;
            NGAbs = j;
         }
      }

      garm_amax[i] = GarmMaxAbs;
      garm_gmax[i] = NGAbs;

      if(i%10==0) Form1->ProgressBar1->Position+=1;
   }

}

int __fastcall DetErrObor(){
  int i,j;
  float buf_det[NBUF_DET_PEREHOD];
  int cnt_det = 0;
  int MaxD = 0;
  int MinD = 0;
  float DeltaD;
  int cnt_err_ob = 0;
   float PecTime = StrToFloat(Form1->LabeledEdit2->Text); //с каким процентом отклонения от среднего игнорировать оборот

  for(j=0;j<NBUF_DET_PEREHOD-1;j++){
     buf_det[j]=time_buf[j];
  }

  for(i=(NBUF_DET_PEREHOD-1);i<NumHei-NBUF_DET_PEREHOD;i++){

    buf_det[cnt_det] = time_buf[i];
    cnt_det++;
    if(cnt_det==NBUF_DET_PEREHOD) cnt_det=0;

    MaxD = buf_det[0];
    MinD = buf_det[0];
    for(j=1;j<NBUF_DET_PEREHOD;j++){
       if (buf_det[j]>MaxD) MaxD = buf_det[j];
       if (buf_det[j]<MinD) MinD = buf_det[j];
    }

    DeltaD = ((float)(MaxD-MinD)*100.0)/MaxD;

    if(DeltaD>PecTime){
       ObErr[cnt_err_ob] = i;
       cnt_err_ob++;
    }

  }
  return cnt_err_ob;
}


int __fastcall Calc_Ob_Reductor(){
   int i,j,q,k,s;
   float TObor;
   float buf_ob[MAX_LEN_OB]; //буфер данных оборота
   float Fcentr;
   float GAbs;
   int NGAbs;
   int NumObr = 0;
   int NumObrTmp = 0;
   GarmMaxAbs =  0;
   float Postoyanka;
   int MaxObor = 0;
   int MinObor = 0;
   float KSampleObor;
   bool FlError = false;
   int cnt_err_obr = 0;
   int cnt_err_dop = 0;
   int SkzozOb = 0;
   int CntIgnor = 0;
   int Pred = 0;

   Form1->ListBox2->Clear();

   for(i=NOborFix;i<(NumHei-(NOborFix+1));i+=NOborFix){

      k=hei_buf[i+NOborFix]-hei_buf[i];
      k = (int)((float)k*KRed);
      s = hei_buf[i];

   //---------- проверяем не является ли этот оборот косячным --------------------
      if(cnt_err_obr < NumErrD){
         if(ObErr[cnt_err_obr]<i) cnt_err_obr++;
      }

      if(cnt_err_obr < NumErrD){
         if( (ObErr[cnt_err_obr]==i) || (ObErr[cnt_err_obr]==(i+1)) ){
            FlError=true;
            cnt_err_obr++;
            Pred = i;
         }
         else if( (ObErr[cnt_err_obr]==(i+2)) || (ObErr[cnt_err_obr]==(i+3)) ){
            FlError=true;
         }
         //проверяем если был предыдущий тогда и следующий с запасом удаляем
         if(cnt_err_obr>0){
           if(Pred==(i-NOborFix)){
               FlError=true;
           }
         }

      }
   //------------------------------------------------------------------------

      if((FlError==false) && (k>30) && (k<30000)){

         Oboroty_Obr_Tmp[0][NumObr] = s;
         Oboroty_Obr_Tmp[1][NumObr] = k;
         if(Form1->RadioGroup4->ItemIndex>0) time_buf_dv2[NumObr] = time_buf_dv[SkzozOb];
         NumObr++;
       }
      else{
          Form1->ListBox2->Items->Add("Игнор. об: " + IntToStr(SkzozOb));
          ObErrAvto[CntIgnor] = SkzozOb;
          CntIgnor++;

      }

      SkzozOb++;
      FlError=false;
   }


//выкидываем обороты удаленные в ручном режиме

  if(NumErrDop>0){
     Form1->ListBox2->Items->Add(" ");
     Form1->ListBox2->Items->Add("Добавл-ые игнор. об.");
     NumObrTmp = 0;
     for(i=0;i<NumObr;i++){

        for(j=0;j<NumErrDop;j++){
            if(ObErrDop[j]==i){
              FlError=true;
              Form1->ListBox2->Items->Add("Игнор. об: " + IntToStr(i));
            }
        }

        if(FlError==false){
           Oboroty_Obr[0][NumObrTmp] = Oboroty_Obr_Tmp[0][i];
           Oboroty_Obr[1][NumObrTmp] = Oboroty_Obr_Tmp[1][i];
           if(Form1->RadioGroup4->ItemIndex>0) time_buf_dv[NumObrTmp] = time_buf_dv2[i];
           NumObrTmp++;
        }

        FlError=false;
     }
     NumObr = NumObrTmp;
  }
  else{
     for(i=0;i<NumObr;i++){
        Oboroty_Obr[0][i] = Oboroty_Obr_Tmp[0][i];
        Oboroty_Obr[1][i] = Oboroty_Obr_Tmp[1][i];
        if(Form1->RadioGroup4->ItemIndex>0) time_buf_dv[i] = time_buf_dv2[i];
     }
  }

//--------- вычиляем обороты --------------------

   for(i=0;i<NumObr;i++){

         k = Oboroty_Obr[1][i];
         TObor =k*Tfd;  //сек

         if(Form1->RadioGroup4->ItemIndex==0){
           time_buf_dv[i] = (60.0/TObor)*2;      //обор/мин
           time_buf_dv2[i] = (60.0/TObor)*2;
         }
         else{
           time_buf_dv2[i] = time_buf_dv[i];
         }

         if((i)>0){
            if(time_buf_dv[i]<MinObor) MinObor = time_buf_dv[i];
            if(time_buf_dv[i]>MaxObor) MaxObor = time_buf_dv[i];
         }
         else{
            MaxObor = time_buf_dv[0];
            MinObor = time_buf_dv[0];
         }
   }

  Form1->ListBox1->Items->Add(" ");
  Form1->ListBox1->Items->Add("Инф об.с учетом такт.и ред.: ");
  Form1->ListBox1->Items->Add("Найдено. об.: " + IntToStr(SkzozOb));
  Form1->ListBox1->Items->Add("Обраб. об.: " + IntToStr(NumObr));
  Form1->ListBox1->Items->Add("Игнор. об.: " + IntToStr(CntIgnor));

  return NumObr;
}

int __fastcall Calc_Garm_Usr(){
   int i,j,z,k,s;
   float WinUsr = StrToFloat(Form1->LabeledEdit14->Text);  //шаг границе оборотов (окно усреднения)
   float AmplErr = StrToFloat(Form1->LabeledEdit15->Text); //% отличия амплитуды от соседних когда считать оборот ошибочным
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);  //на сколько раскладывать гармоник
   int MaxGarmUsr;
   int Oborot_Start;  //текущий оборот
   float Oborot_Usr; //усредненый оборот
   int IndMax;  //текущий оборот
   float DeltaOb;
   float DeltaG;
   int cnt_obor = 0;
   int cnt_obr_obor = 0;
   int cnt_usr = 0;
   int NOborObr;
   int Cnt_Oborot_Usr;
   float garm_usr[64];
   short GoodObor[8192];
/* TEST
FILE* out1 = fopen("D:\sort1.dat", "w+");
FILE* out2 = fopen("D:\sort2.dat", "w+");
FILE* out3 = fopen("D:\dv2.dat", "w+");
*/
   if(NumHeiObr>3){

     Form1->ProgressBar1->Position=0;
     Form1->ProgressBar1->Max = NumHeiObr/10;
     Form1->Label16->Caption = "Вычисление уср. гармоник";

     NOborObr = NumHeiObr;
     cnt_obor = 0;

/* TEST
     for(i=1;i<NumHeiObr-1;i++){
        fprintf(out3,"%f\n", time_buf_dv2[i]);
     }
*/

     while(NOborObr!=0){

       IndMax = 0;

       for(i=1;i<NumHeiObr;i++){
         if(time_buf_dv2[i]>time_buf_dv2[IndMax]) IndMax = i;
       }

       time_buf_sort[0][cnt_obor] = time_buf_dv2[IndMax];
       time_buf_sort[1][cnt_obor] = (float)IndMax;
       time_buf_dv2[IndMax] = 0;
       NOborObr--;
       cnt_obor++;

     }

/* TEST
        for(i=1;i<NumHeiObr-1;i++){
                fprintf(out1,"%f\n", time_buf_sort[0][i]);
                fprintf(out2,"%f\n", time_buf_sort[1][i]);
        }

        fclose(out1);
        fclose(out2);
        fclose(out3);
*/
     //IndMax = 2281;


     NOborObr = NumHeiObr;
     cnt_obor = 1;
     Oborot_Start = 0;

     for(i=1;i<NumHeiObr-1;i++){

       DeltaOb = time_buf_sort[0][Oborot_Start]-time_buf_sort[0][i];

       if(DeltaOb>WinUsr){

         cnt_obr_obor = 0;

         if(cnt_obor>1){
        //------- предварительное вычисление среднего для определения косячных оборотов по амплитуде
           for(j=0;j<NGarm;j++) garm_usr[j] = 0;

           for(j=0;j<NGarm;j++){  //
              for(z=0;z<cnt_obor;z++){
                 k = time_buf_sort[1][Oborot_Start+z];
                 garm_usr[j] += data_garm_abs[j][k];
              }
           }

           for(j=0;j<NGarm;j++){
             garm_usr[j]/=cnt_obor;
           }

           MaxGarmUsr = 1;   //определение номера максимальной гармоники
           for(j=2;j<NGarm;j++){
             if(garm_usr[j]>garm_usr[MaxGarmUsr]) MaxGarmUsr = j;
           }

         //----------------------------------------------------------------------------------------

        //------- определение косячных оборотов по амплитуде -------------------------------------

           for(z=0;z<cnt_obor;z++){

              k = time_buf_sort[1][Oborot_Start+z];
              DeltaG = garm_usr[MaxGarmUsr]- garm_amax[k];
              if(DeltaG<0) DeltaG = -DeltaG;
              DeltaG = (DeltaG*100)/garm_usr[MaxGarmUsr];

              if(DeltaG<AmplErr){
                 GoodObor[z] = 1;
                 cnt_obr_obor++;
              }else{
                 GoodObor[z] = 0;
              }

           }
          //---------------------------------------------------------------------------------------
          }

           if(cnt_obr_obor==0){
             cnt_obr_obor = 1;
             GoodObor[0] = 1;
           }

          cnt_obr_obor = cnt_obor;

          for(j=0;j<NGarm;j++) data_garm_usr[j][cnt_usr] = 0.0;

          //вычисляем среднее гармоник
          for(z=0;z<cnt_obor;z++){
             if(GoodObor[z]==1){
               k = time_buf_sort[1][Oborot_Start+z];
               for(j=0;j<NGarm;j++){  //
                  data_garm_usr[j][cnt_usr] += data_garm_abs[j][k];
               }
             }
          }

           for(j=0;j<NGarm;j++){
             data_garm_usr[j][cnt_usr]/=(cnt_obr_obor);
           }

           Oborot_Usr = 0;
           Cnt_Oborot_Usr = 0;
           for(z=0;z<cnt_obor;z++){
              if(GoodObor[z]==1){
                 Oborot_Usr+=time_buf_sort[0][Oborot_Start+z];
                 Cnt_Oborot_Usr++;
              }
           }

           Oborot_Usr = Oborot_Usr/Cnt_Oborot_Usr;

           if(cnt_usr>0){
              DeltaOb = data_usr_obor[cnt_usr-1]-Oborot_Usr;
              if(DeltaOb<(WinUsr*1.5)) data_usr_obor[cnt_usr] = data_usr_obor[cnt_usr-1]-WinUsr;
              else data_usr_obor[cnt_usr] = (float)((int)Oborot_Usr);
           }else{
              data_usr_obor[cnt_usr] = (float)((int)Oborot_Usr);
           }

           cnt_usr++;
           Oborot_Start = i;
           cnt_obor = 1;

           if(i%10==0) Form1->ProgressBar1->Position+=1;

       }
       else{
         cnt_obor++;
       }

     }

   }

   return cnt_usr;
}

void __fastcall ViewGarmUsr(){
   int i,j,k;
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);
//   float KRed = StrToFloat(Form1->LabeledEdit10->Text); //коэф. редукции
   Form1->Chart3->Axes->Bottom->Maximum = OborUsr;

   for(i=0;i<N_MAX_GARM;i++){
      Form1->Chart3->Series[i]->Clear();
   }
   for(j=0;j<NGarm;j++){
      if(Form1->CheckListBox1->Checked[j]==true){
         for(i=0;i<OborUsr;i++){
           Form1->Chart3->Series[j]->AddY(data_garm_usr[j][(OborUsr-1)-i],(int)data_usr_obor[(OborUsr-1)-i]);    //
         }
      }
   }
}


void __fastcall ViewGarm(){
   int i,j,k;
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);
   float GAbs;
//   Form1->Chart3->Axes->Left->Maximum = GarmMaxAbs+0.05*GarmMaxAbs;
//   Form1->Chart3->Axes->Left->Minimum = 0;
   Form1->Chart3->Axes->Bottom->Maximum = NumHeiObr;

   for(i=0;i<N_MAX_GARM;i++){
      Form1->Chart3->Series[i]->Clear();
   }
   for(j=0;j<NGarm;j++){
      if(Form1->CheckListBox1->Checked[j]==true){
            for(i=0;i<NumHeiObr;i++){
               GAbs = abs(data_garm[j][i]);
               Form1->Chart3->Series[j]->AddY((double)GAbs);
            }

      }
   }

}

void __fastcall ViewGarm_All(){
   int i,j,k;
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);
   float GAbs;
   Form1->Chart3->Axes->Left->Maximum = GarmMaxAbs+0.05*GarmMaxAbs;
   Form1->Chart3->Axes->Left->Minimum = 0;
   Form1->Chart3->Axes->Bottom->Maximum = NumHeiObr;

   for(i=0;i<N_MAX_GARM;i++){
      Form1->Chart3->Series[i]->Clear();
   }
   for(j=0;j<NGarm;j++){
      if(Form1->CheckListBox1->Checked[j]==true){
            for(i=0;i<NumHeiObr;i++){
               GAbs = sqrt(data_garm[j][i]._M_re*data_garm[j][i]._M_re+data_garm[j][i]._M_im*data_garm[j][i]._M_im);
               Form1->Chart3->Series[0]->AddY((double)GAbs);
            }

      }
   }

}

void __fastcall TForm1::CheckListBox1Click(TObject *Sender)
{
    if(RadioGroup2->ItemIndex==1){
       ViewGarm();
    }
    else{
       ViewGarmUsr();
    }    
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button6Click(TObject *Sender){
int i;
int StartT, StopT;
int St = (LENWINP+1)/2;
if(RadioGroup4->ItemIndex>0){
    if(Fl_OK==false){

       if(!FlAnaliz){
          LabeledEdit11->Text =  UpDown2->Position*NumEncView;
          Fl_OK = true;
       }
       else if((RadioGroup5->ItemIndex==1) && (FlAnaliz)){

         StartT = StrToInt(LabeledEdit11->Text);
         StopT = StrToInt(LabeledEdit13->Text);

         Len_Enc_Data = StopT-StartT;
         Len_Data = Len_Enc_Data;
         Len_Data_View = Len_Data;
         
         LabeledEdit11->Text = "0";
         LabeledEdit13->Text = IntToStr(Len_Enc_Data);

         Chart2->BottomAxis->Minimum = 0;
         Chart2->BottomAxis->Maximum = Len_Data;

         for(i=StartT;i<StopT;i++){
           data_buf_prep[1][i-StartT] = data_buf_prep[1][i];
           EncPorogT[i-StartT] = EncPorogT[i];
         }

         ViewTEnc();
         Fl_Zoomed = false;

       }

    }
    else{
       LabeledEdit13->Text =  UpDown2->Position*NumEncView;
       Fl_OK = false;
    }
}
else{
    Fl_OK = true;
    Fl_Zoomed = false;

    StartT = StrToInt(LabeledEdit11->Text);
    StopT = StrToInt(LabeledEdit13->Text);

    for(i=StartT;i<StopT;i++){
       data_buf_prep[0][i-StartT] = data_buf_prep[0][i];
       data_buf_prep[1][i-StartT] = data_buf_prep[1][i];
    }

    Len_Data_View = StopT-StartT;
    Len_Data = Len_Data_View;

    LabeledEdit11->Text = "0";
    LabeledEdit13->Text = IntToStr(Len_Data_View);
    Data_View_Start = 0;

    Chart2->BottomAxis->Minimum = 0;
    Chart2->BottomAxis->Maximum = Len_Data;

    TrackBar1->Position = 0;
    TrackBar1->Max = Len_Data_View/BlockView;

    Calc_Param();
    Paint_Char();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
if(RadioButton1->Checked){
  LabeledEdit11->Text =  0;
  LabeledEdit13->Text =  NumSampleEnc;
}else{
  Data_View_Start = 0;
  Len_Data_View = Len_File_Data;

  LabeledEdit11->Text =  "0";
  LabeledEdit13->Text = IntToStr(Len_Data_View);

  TrackBar1->Position = 0;
  TrackBar1->Max = Len_Data_View;

  Calc_Param();
  Paint_Char();
}
}
//---------------------------------------------------------------------------

void __fastcall View_Garm_Obor(int nt){
   int i;
   int NGarm = StrToInt(Form1->LabeledEdit12->Text);
   int TactD =  StrToInt(Form1->ComboBox1->Text); //тактность двигателя
   float GAbs;

   Form1->Chart4->Axes->Bottom->Maximum = NGarm;
   Form1->Chart4->Series[0]->Clear();
   Form1->Chart4->Series[1]->Clear();

   if(Form1->RadioGroup2->ItemIndex == 1){

     for(i=0;i<NGarm;i++){
       GAbs = abs(data_garm[i][nt]);
       if(Form1->CheckListBox1->Checked[i]==true) Form1->Chart4->Series[0]->AddY((double)GAbs, (float)i/(float)(TactDv/2));
       else Form1->Chart4->Series[0]->AddY(0.0, (float)i/(float)NOborFix);
     }

   }else{

     for(i=0;i<NGarm;i++){
       if(Form1->CheckListBox1->Checked[i]==true) Form1->Chart4->Series[0]->AddY(data_garm_usr[i][(OborUsr-1)-nt],(float)i/(float)(TactDv/2));
       else Form1->Chart4->Series[0]->AddY(0.0, (float)i/(float)(TactDv/2));
     }

   }
}

void __fastcall View_Obor_Data(int nt){
   int i,k,s;
   float postoyanka = 0;
   float tob,obm;

   s = Oboroty_Obr[0][nt];
   k = Oboroty_Obr[1][nt];

   if(Form1->CheckBox23->Checked){
      k = k+Oboroty_Obr[1][nt+3];
   }

   Form1->Chart5->Axes->Bottom->Maximum = k;
   Form1->Chart5->Series[0]->Clear();

   for(i=0;i<k;i++){
      postoyanka+=data_buf_prep[0][s+i];
   }
   postoyanka/=k;
   for(i=0;i<k;i++){
      Form1->Chart5->Series[0]->AddY((double)(data_buf_prep[0][s+i]-postoyanka));
   }

   obm = time_buf_dv[nt];

   //Form1->Label21->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
   Form1->Chart3->Title->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
   //Form1->Label23->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
   Form1->Chart5->Title->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
   //Form1->Chart3->Hint = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
}


void __fastcall TForm1::Chart3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  double pX,pY;

  Chart3->Series[0]->GetCursorValues(pX,pY);
  Label11->Caption = "№ : "+IntToStr((int)pX);
  if((RadioButton5->Checked) && (CheckBox5->Checked)){
     View_Garm_Obor((int)pX);
     
     if(RadioGroup2->ItemIndex==1){
       View_Obor_Data((int)pX);
       Label12->Caption = "№ : "+IntToStr((int)pX);
     }
     else{
       //Label12->Caption = "№ : "+FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       //Label21->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       Form1->Chart3->Title->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       //Label23->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       Form1->Chart5->Title->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
     }
  }
  else if((RadioButton8->Checked) && (CheckBox5->Checked)){
      Obor_FFT((int)pX);
      Label12->Caption = " ";
  }
  //Label12->Caption = ": " + Series2->GetHorizAxis->LabelValue(((int)pX)*(timeob) + " с";
  //Label8->Caption = Series2->GetVertAxis->LabelValue(pY);
  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   double pX,pY;
   int numt;
   if((RadioButton5->Checked) && (!CheckBox5->Checked)){
     Chart3->Series[0]->GetCursorValues(pX,pY);
     View_Garm_Obor((int)pX);
     if(RadioGroup2->ItemIndex==1){
       if(RadioGroup4->ItemIndex>0) numt = (int)(pX/(2/NOborFix));
       else  numt = (int)pX;
       View_Obor_Data(numt);
       OborDataView = (int)pX;
       Label12->Caption = "№ : "+IntToStr((int)pX);

     }
     else{
       //Label12->Caption = "№ : "+FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       Label21->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       Form1->Chart3->Title->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       //Label23->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);
       Form1->Chart5->Title->Caption = "Об/мин: " + FloatToStr(data_usr_obor[(OborUsr-1)-(int)pX]);

     }
   }

   else if((RadioButton8->Checked) && (!CheckBox5->Checked)){
      Chart3->Series[0]->GetCursorValues(pX,pY);
      Obor_FFT((int)pX);
      Label12->Caption = "№ об.: "+IntToStr((int)pX);
   }

}
//---------------------------------------------------------------------------
void Obor_FFT(int nt){
   int i,k,s;
   float GAbs;
   complex<float> buf_ob[16384]; //буфер данных оборота
   float fft_rez[16384]; //буфер гармоник для одного оборота

     k=hei_buf[nt*NOborFix+NOborFix]-hei_buf[nt*NOborFix];
     if(k>16384) k=16384;
     s = hei_buf[nt*NOborFix];
     for(i=0;i<k;i++){
           buf_ob[i]._M_re = data_buf_prep[0][s+i]-Mean[0];  //закидываем оборот в буфер и вычитаем постоянку
           buf_ob[i]._M_im = 0.0;
     }
     if(k<=128) k=128;
     else if(k<=256) k=256;
     else if(k<=512) k=512;
     else if(k<=1024) k=1024;
     else if(k<=2048) k=2048;
     else if(k<=4096) k=4096;
     else if(k<=8192) k=8192;
     else k=16384;

     Fft(1, k, buf_ob);

     Form1->Chart4->Axes->Bottom->Maximum = k/2;
     Form1->Chart4->Series[0]->Clear();

     for(i=0;i<k/2;i++){
       GAbs = sqrt(buf_ob[i]._M_re*buf_ob[i]._M_re+buf_ob[i]._M_im*buf_ob[i]._M_im);
       Form1->Chart4->Series[0]->AddY((double)GAbs);
     }
}

void __fastcall Fft(int isign, int num_time, complex<float> *data)
{
//      Быстрое преобразование Фурье

 // направление преобразования:
 // isign = 1 - прямое, isign = -1 - обратное
 // num_time - размер преобразования (обязательно кратен 2)

 int n, k, i, j, mmax, istep;
 complex<float> temp, w, wp;
 float theta;

 // прореживание во временной области

 n=num_time>>1;
 j=0;
 for(i=0;i<num_time;i++)
       {
        if(i<j)
              {
               temp=data[j];
               data[j]=data[i];
               data[i]=temp;
              }
        k=n;
        while((k>1)&&(k<=j))
              {
               j-=k;
               k>>=1;
              }
        j+=k;
       }
 mmax=1;
 while(n>=mmax)
       {
        istep=mmax<<1;
        theta=-isign*(M_PI/mmax);
        wp=complex<float> (cos(theta), sin(theta));
        w=complex<float> (1., 0.);
        for(k=0;k<mmax;k++)
              {
               for(i=k;i<num_time;i+=istep)
                       {
                        j=i+mmax;
                        temp=data[j]*w;
                        data[j]=data[i]-temp;
                        data[i]+=temp;
                       }
               w*=wp;
              }
        mmax=istep;
       }

       for(i=0;i<num_time;i++) data[i]/=(float)sqrt(num_time);

}

void __fastcall TForm1::Chart1Zoom(TObject *Sender)
{
//  int a1,a2,a3,a4;
if(RadioGroup4->ItemIndex==0){

  Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Fl_Zoomed = true;

//  a1 =  (int)Chart1->BottomAxis->Minimum;
//  a2 = UpDown2->Max;
//  a3 = TrackBar1->Max;

  TrackBar1->Position = StrToInt(LabeledEdit11->Text)/BlockView;
  UpDown2->Position = TrackBar1->Position;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1UndoZoom(TObject *Sender)
{

if(RadioGroup4->ItemIndex==0){

if(Fl_OK == false){
  Chart2->BottomAxis->Maximum = Chart1->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = Chart1->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Fl_Zoomed = false;

}
else{
  Chart2->BottomAxis->Minimum = 0;
  Chart1->BottomAxis->Minimum = 0;
  Chart2->BottomAxis->Maximum = Len_Data_View;
  Chart1->BottomAxis->Maximum = Len_Data_View;
  Fl_OK = false;
}

  TrackBar1->Position = StrToInt(LabeledEdit11->Text)/BlockView;
  UpDown2->Position = TrackBar1->Position;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart2Zoom(TObject *Sender)
{
if(RadioGroup4->ItemIndex==0){

  Chart1->BottomAxis->Maximum = Chart2->BottomAxis->Maximum;
  Chart1->BottomAxis->Minimum = Chart2->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Fl_Zoomed = true;

  TrackBar1->Position = StrToInt(LabeledEdit11->Text)/BlockView;
  UpDown2->Position = TrackBar1->Position;
}
else{
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Fl_Zoomed = true;
//  TrackBar1->Position = StrToInt(LabeledEdit11->Text)/BlockView;
//  UpDown2->Position = TrackBar1->Position;  
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart2UndoZoom(TObject *Sender)
{

if(RadioGroup4->ItemIndex==0){

if(Fl_OK == false){
  Chart1->BottomAxis->Maximum = Chart2->BottomAxis->Maximum;
  Chart1->BottomAxis->Minimum = Chart2->BottomAxis->Minimum;
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Fl_Zoomed = false;
}
else{
  Chart2->BottomAxis->Minimum = 0;
  Chart1->BottomAxis->Minimum = 0;
  Chart2->BottomAxis->Maximum = Len_Data_View;
  Chart1->BottomAxis->Maximum = Len_Data_View;
  Fl_OK = false;
}

  TrackBar1->Position = StrToInt(LabeledEdit11->Text)/BlockView;
  UpDown2->Position = TrackBar1->Position;
}
else{
  LabeledEdit11->Text =  (int)Chart2->BottomAxis->Minimum;
  LabeledEdit13->Text =  (int)Chart2->BottomAxis->Maximum;
  Chart2->BottomAxis->Minimum = 0;
  Chart2->BottomAxis->Maximum = Len_Data_View;
  Fl_Zoomed = false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart4MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  double pX,pY;
  Chart4->Series[0]->GetCursorValues(pX,pY);
  Label9->Caption = "№ : "+IntToStr((int)pX);
  Label13->Caption = "Знач.: "+IntToStr((int)pY);
  Label12->Caption = " ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
   if(NumHeiObr>0){
     View_Garm_Obor(0);
     Label12->Caption = "№ : "+IntToStr(0);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
   View_Ob();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
   if(NumHeiObr>0){
      Obor_FFT(0);
      Label12->Caption = "№ : "+IntToStr(0);
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit1KeyPress(TObject *Sender, char &Key)
{
   float por;
   int i;

   if(Key==13){

     if(Form1->CheckBox4->Checked) por = Mean[1]*StrToFloat(Form1->LabeledEdit1->Text);
     else por = StrToFloat(Form1->LabeledEdit1->Text);

     Form1->Chart2->Series[1]->Clear();

     for(i=0;i<Len_Data_View;i++){
        Form1->Chart2->Series[1]->AddY((double)por);
     }
     Form1->Chart2->Series[1]->Repaint();
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox6Click(TObject *Sender)
{
    if(CheckBox6->Checked){
      ViewGarm_All();
    }
    else{
       ViewGarm();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
   Paint_Char();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
   Paint_Char();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
   View_Ob();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
    if(RadioGroup2->ItemIndex==1){
       ViewGarm();
       if(CheckBox5->Checked==false) Button8->Enabled = true;
       TrackBar2->Position = 0;
       TrackBar2->Max = NumHeiObr;
       UpDown3->Position = 0;
       UpDown3->Max = NumHeiObr;
    }
    else{
       ViewGarmUsr();
       Button8->Enabled = false;
       TrackBar2->Position = 0;
       TrackBar2->Max = OborUsr;
       UpDown3->Position = 0;
       UpDown3->Max = OborUsr;
    }        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox9Click(TObject *Sender)
{
   if(NumHeiObr>0){
     View_Garm_Obor(0);
     Label12->Caption = "№ : "+IntToStr(0);
   }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton9Click(TObject *Sender)
{
   int i;
   Form1->Chart4->Axes->Bottom->Maximum = OborUsr;
   Form1->Chart4->Series[0]->Clear();
   Form1->Chart4->Series[1]->Clear();
   
   for(i=1;i<OborUsr;i++){
      Form1->Chart4->Series[0]->AddY(data_usr_obor[(OborUsr-1)-i]);
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
   int i,j;
   float sample;
   AnsiString Nfile;
   AnsiString Sfile;
   AnsiString StrGarms;
   FILE* out;

   int NGarm = StrToInt(Form1->LabeledEdit12->Text);

   if(SaveDialog1->Execute()){

      Nfile = SaveDialog1->FileName;
      Sfile = Nfile+".dat";
      out = fopen(Sfile.c_str(), "w+");

      for(i=0;i<OborUsr;i++){

         sample = data_usr_obor[(OborUsr-1)-i];
         fprintf(out,"%f", sample);
         fprintf(out,"       ", sample);

         for(j=0;j<NGarm-1;j++){
            sample = data_garm_usr[j][(OborUsr-1)-i];
            fprintf(out,"%f", sample);
            fprintf(out,"       ");
         }

         sample = data_garm_usr[NGarm-1][(OborUsr-1)-i];
         fprintf(out,"%f\n", sample);
      }

      fclose(out);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   int i,k,s;
   float sample;
   float postoyanka = 0;
   AnsiString Nfile;
   FILE* out;

   s = Oboroty_Obr[0][OborDataView];
   k = Oboroty_Obr[1][OborDataView];

   if(SaveDialog1->Execute()){

      Nfile = SaveDialog1->FileName;
      Nfile = Nfile+".dat";
      out = fopen(Nfile.c_str(), "w+");

      for(i=0;i<k;i++) postoyanka+=data_buf_prep[0][s+i];

      postoyanka/=k;

      fprintf(out,"%f\n", postoyanka);

      for(i=0;i<k;i++){
         sample = data_buf_prep[0][s+i]-postoyanka;
         fprintf(out,"%f\n", sample);
      }

      fclose(out);

   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
 if((CheckBox5->Checked==true) && (RadioGroup2->ItemIndex==1)) Button8->Enabled = true;
 else Button8->Enabled = false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::UpDown3Click(TObject *Sender, TUDBtnType Button)
{
  int mx = Chart3->BottomAxis->Maximum;
  int mn = Chart3->BottomAxis->Minimum;
  int Granica;

  if(RadioGroup2->ItemIndex==1){
     Granica = NumHeiObr;
  }
  else{
     Granica = OborUsr;
  }

  if((Button == btNext) && ((mx+1)<=Granica)) {
    Chart3->BottomAxis->Maximum+=1;
    Chart3->BottomAxis->Minimum+=1;
  }
  else if((Button == btPrev) && ((mn-1)>=0)){
    Chart3->BottomAxis->Minimum-=1;
    Chart3->BottomAxis->Maximum-=1;
  }

  TrackBar2->Position = (int)Chart3->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
  int mx = Chart3->BottomAxis->Maximum-Chart3->BottomAxis->Minimum;

  Chart3->BottomAxis->Minimum=TrackBar2->Position;
  Chart3->BottomAxis->Maximum=Chart3->BottomAxis->Minimum+mx;

  UpDown3->Position = TrackBar2->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   if(Fl_Syem==false){
       Fl_Syem=true;
       Button3->Caption = "Отмена";
   }
   else{
       Cnt_Syem = false;
       Fl_Syem=false;
       LabeledEdit17->Text = "0";
       LabeledEdit18->Text = "0";
       Button3->Caption = "Снять";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
   int start = StrToInt(LabeledEdit17->Text);
   int stop = StrToInt(LabeledEdit18->Text);
   int Len;
   int i;
   float p = 0;
   if(stop>start){

      Form1->ProgressBar1->Position=0;
      Form1->ProgressBar1->Max = Len_Data_View/500;
      Label16->Caption = "Вычитание смещения";

      Len = stop-start;
      for(i=0;i<Len;i++){
         p += data_buf_prep[0][i+start];
      }

      p/=Len;

      for(i=0;i<Len_File_Data;i++){
         data_buf_prep[0][i] = data_buf_prep[0][i]-p;
         if(i%500==0) Form1->ProgressBar1->Position+=1;
      }

      Cnt_Syem = false;
      Fl_Syem=false;
      LabeledEdit17->Text = "0";
      LabeledEdit18->Text = "0";
      Button3->Caption = "Снять";
      Label15->Caption = "Значение: "+IntToStr((int)p);

      Calc_Param();
      Paint_Char();

   }
   else{
      ListBox1->Items->Add("Неверные значения старт/стоп");
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 double pX,pY;
 float tob, obm;
 int i,k;
 int NumO = 0;
 int a,b,delta;
 Series1->GetCursorValues(pX,pY);

 if(Fl_Syem){

   if(Cnt_Syem==false){
     LabeledEdit17->Text = IntToStr((int)pX);
     Cnt_Syem = true;
   }
   else{
     LabeledEdit18->Text = IntToStr((int)pX);
     Cnt_Syem = false;
   }
 }
 else if(!CheckBox10->Checked){

    if((Len_Data>BlockZoomView*2) && (pX>0)){

      Series1->GetCursorValues(pX,pY);  // <-- get values under mouse cursor
      Label2->Caption = (int)pX;
      Label4->Caption = ": " + Series1->GetHorizAxis->LabelValue(pX*(1/Fd)) + " с";
      Label5->Caption = Series1->GetVertAxis->LabelValue(pY);

      k = (int)pX+Data_View_Start;
      //ищем к кокому обороту принадлежит данный отсчет
      if(NumHei>3){
         for(i=0;i<NumHei-1;i++){
           if((hei_buf[i]<k)&&(hei_buf[i+1]>=k)){
              NumO = i;
              break;
           }
         }
         Chart6->Series[0]->Clear();


         a = hei_buf[NumO];
         b = hei_buf[NumO+1];
         delta = b-a;

         if(RadioGroup4->ItemIndex==0){
           tob = delta*Tfd;
           obm = 60.0/tob;
           Label20->Caption = "№ Об: " + IntToStr(NumO)+ "; Время Об:" + FloatToStrF(tob, ffGeneral, 4,4)+"; Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Chart1->Hint = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Label22->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
         }
         else{
           tob = time_buf[NumO]/1000.0;
           obm = 60.0/tob;
           Label20->Caption = "№ Об: " + IntToStr(NumO)+ "; Время Об:" + FloatToStrF(tob, ffGeneral, 4,4)+"; Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Chart1->Hint = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
           Label22->Caption = "Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);
         }

         for(i=0;i<delta;i++){
           Chart6->Series[0]->AddY(data_buf_prep[0][a+i]);
         }

      }
    }
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit16KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      BlockView = StrToInt(LabeledEdit16->Text);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
   int i;
   float koeff = StrToFloat(LabeledEdit19->Text);

   Form1->ProgressBar1->Position=0;
   Form1->ProgressBar1->Max = Len_Data_View/500;
   Label16->Caption = "Умножение на коэф.";

   for(i=0;i<Len_File_Data;i++){
      data_buf_prep[0][i] = data_buf_prep[0][i]*koeff;
      if(i%500==0) Form1->ProgressBar1->Position+=1;
   }

   Calc_Param();
   Paint_Char();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button14Click(TObject *Sender)
{
int i;
float d;

     Chart7->Axes->Left->Maximum = 20000;
     Chart7->Axes->Left->Minimum = 0;

  if(OpenDialog1->Execute()){
    DFile = OpenDialog1->FileName;
    Chart7->Series[0]->Clear();
    Chart8->Series[0]->Clear();
    //ifstream EData(DFile.c_str(), ios::in|ios::binary);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
int i;
int d_ch;
char tmpb;
char* ptrb = (char*)&d_ch;
int offs = StrToInt(Edit3->Text);

 ifstream EData(DFile.c_str(), ios::in|ios::binary);

   //EData.read((char*)&tmpb,sizeof(tmpb));
   Chart8->Series[0]->Clear();

   for(i=0;i<offs;i++){
      EData.read((char*)&tmpb,sizeof(tmpb));
   }

   for(i=0;i<8192;i++){

     d_ch = 0;

     EData.read(ptrb+0,1);
     EData.read(ptrb+1,1);
     EData.read(ptrb+2,1);
     EData.read(ptrb+3,1);

      if(CheckBox11->Checked){
         tmpb = ptrb[0];
         ptrb[0] = ptrb[1];
         ptrb[1] = tmpb;
      }
      //ptrb[3] = 0;
      //d_ch = d_ch>>8;
      Chart8->Series[0]->AddY(((float)d_ch)*0.000232544);

//      EData.read((char*)&d_ch,sizeof(d_ch));
/*    tmpb = ptrb[0];
      ptrb[0] = ptrb[1];
      ptrb[1] = tmpb;
*/
      //data_buf_encod[i]= (float)d_ch;
      //d_ch = d_ch-14000;
      //if(d_ch<0) d_ch = -d_ch;
//      Chart7->Series[0]->AddY((float)d_ch);
   }

   EData.close();

}
//---------------------------------------------------------------------------

void View_Data_Enc(int nd){
   int i;

   Form1->ProgressBar1->Position=0;
   Form1->ProgressBar1->Max = nd/500;
   Form1->Label16->Caption = "Отрисовка графика";

   Form1->Chart1->Series[0]->Clear();
   Form1->Chart1->Axes->Bottom->Maximum = nd;

   for(i=0;i<nd;i++){
        Form1->Chart1->Series[0]->AddY((double)data_buf_prep[0][i]);
        if(i%500==0) Form1->ProgressBar1->Position+=1;
   }
   Form1->Chart1->Series[0]->Repaint();
}


void View_tStrob_Enc(int nd){
   int i;
   int cnt = 0;

   Form1->ProgressBar1->Position=0;
   Form1->ProgressBar1->Max = nd/500;
   Form1->Label16->Caption = "Отрисовка графика";

   Form1->Chart2->Series[0]->Clear();
   Form1->Chart2->Axes->Bottom->Maximum = nd;

   for(i=0;i<nd;i++){
        Form1->Chart2->Series[0]->AddY((double)data_buf_prep[1][i]);
        if(i%500==0) Form1->ProgressBar1->Position+=1;
   }
   Form1->Chart2->Series[0]->Repaint();

   Form1->Chart1->Series[0]->Clear();
   Form1->Chart1->Series[1]->Clear();
   Form1->Chart1->Axes->Bottom->Maximum = nd-EncNumMetok;

   for(i=0;i<nd-EncNumMetok;i++){
        Form1->Chart1->Series[0]->AddY((double)data_buf_prep[0][i]);
        if(i == hei_buf[cnt]){
            Form1->Chart1->Series[1]->AddY(1.0);
            cnt++;
        }
        else{
           Form1->Chart1->Series[1]->AddY(0.0);
        }
   }
   Form1->Chart1->Series[0]->Repaint();

}


int ReadF_Data_Enc(int nd, int type){
int i;
int Ld = 0;
short d_ch;
char cbuf[32] = {0};

 if(type==0){
   ifstream inData(DFile.c_str(), ios::in|ios::binary);
   //inData.seekg(posf);
   while(Ld!=nd){
      inData.read((char*)&d_ch,sizeof(d_ch));
      data_buf_prep[0][Ld]=(float)d_ch;
      if(inData.eof()){
          inData.close();
          break;
      }
      if(Ld%300==0) Form1->ProgressBar1->Position+=1;
      Ld++;
   }
   inData.close();

  }
  else if(type==1){

   ifstream inData(DFile.c_str(), ios::in);
   while(Ld!=nd){
      inData.getline(cbuf, sizeof(cbuf));
      data_buf_prep[0][Ld]=StrToFloat(cbuf);
      if(inData.eof()){
          inData.close();
          break;
      }
      if(Ld%300==0) Form1->ProgressBar1->Position+=1;
      Ld++;
   }

  }
  return Ld;
}


int Calc_T_EncT(){

int i;
int Ld = 0;
short binSample;
float d_ch;
char cbuf[32] = {0};
int cntT = 0;
int tp1 = 0;
int tp2 = 0;
float etime = 0;
float Tsr = 0;
bool DetP = false;

   ifstream inData(DFile.c_str(), ios::in);

   //while(!inData.eof()){
   for(i=0;i<Len_Enc_Data;i++){

      //inData.getline(cbuf, sizeof(cbuf));
      d_ch=data_buf_prep[0][Ld];//StrToFloat(cbuf);

      if(DetP==false){
        if(d_ch>PorogEnc){
          DetP = true;
          tp1 = Ld;
        }
      }
      else{
        if(d_ch<PorogEnc){
          DetP = false;
          tp2 = Ld;
          etime = (float)(tp2-tp1)*DtEnc;
          data_buf_prep[1][cntT]=etime*1000.0; //cos(etime*1000.0*2*PI);
          cntT++;
        }
      }
/*
      if(inData.eof()){
          inData.close();
          break;
      }
*/
      if(Ld%300==0) Form1->ProgressBar1->Position+=1;
      Ld++;

      inData.close();
  }

  return cntT;
}

int Syntez_Signal_Enc(){
int i,j;
int CntOb = 0;
int CntT = 0;
float etime = 0;
float Asum = 0;
float Tsr = 0;
float Tact = 4/2;
float Tsum = 0;
float SumTimeOb = 0;
float buf_ob[16000];
bool ErrOb;
float MaxTi = -10000000.0;
float MinTi = 10000000.0;
float DeltaSr;
float PorErrorOb = StrToFloat(Form1->LabeledEdit25->Text);
int Centr = (int)((EncNumMetok*Tact)/2);
int NumTOb = (int)(EncNumMetok*Tact);
float Speedd = (2.0*PI)/(float)EncNumMetok;

   Form1->ProgressBar1->Position = 0;
   Form1->ProgressBar1->Max = Len_Enc_Data/1000;

   for(i=0;i<Len_Enc_Data-EncNumMetokUsred;i++){

      Tsr = 0;
      for(j=0;j<EncNumMetokUsred;j++) Tsr += data_buf_prep[1][i+j];   //вычисляем среднее
      Tsr/=(float)EncNumMetokUsred;

      //ДЛЯ ТЕСТА СРЕДНЕГО
      if(Form1->CheckBox16->Checked){
        if(CntT>=Centr) EncPorogT[CntT] = Tsr;
      }

      etime = data_buf_prep[1][i+Centr];
      Asum += (etime-Tsr)*(Speedd/etime);
      //Tsum+=etime;
      //buf_ob[CntT] = Asum;
      data_buf_prep[0][i] = Asum*1000.0;

      if(MaxTi<etime) MaxTi = etime;
      if(MinTi>etime) MinTi = etime;

      CntT++;

      if(CntT==NumTOb){
/*
         DeltaSr = MaxTi-MinTi;
         DeltaSr = (DeltaSr*100)/MaxTi;
         if(DeltaSr<=PorErrorOb){
            for(j=0;j<NumTOb;j++){ //вытаскиваем оборот в буфер
              data_buf_prep[0][j+(NumTOb*CntOb)] = buf_ob[j];
            }
            CntOb++;
         }
*/
         MaxTi = -10000000.0;
         MinTi = 10000000.0;
         CntOb++;
         CntT = 0;
         Asum = 0.0;

         if(i%1000==0) Form1->ProgressBar1->Position+=1;
      }
   }
return CntOb;
}


int Syntez_Signal_Enc_Lenta(){
int i,j;
int CntOb = 0;
int CntT = 0;
float etime = 0;
float Asum = 0;
float Tsr = 0;
float Tsum = 0;
float SumTimeOb = 0;
float buf_ob[64000];
bool ErrOb;
float MaxTi = -10000000.0;
float MinTi = 10000000.0;
float DeltaSr;
float PorErrorOb = StrToFloat(Form1->LabeledEdit25->Text);
int Tact = StrToInt(Form1->ComboBox1->Text)/2;
int CntObt = 0;
int CntD = 0;
int NumTOb = (int)(EncNumMetok*Tact);
int St = (LENWINP+1)/2;
float Speedd = (2.0*PI)/(float)EncNumMetok;
int CntTableLenta = 0;
int CntObLenta = 0;
int StartD, StopD;

   if(Tact==2) CntObt = 1;

   MaxMetok = 0;
   MinMetok = 10000000;

   Form1->ProgressBar1->Position = 0;
   Form1->ProgressBar1->Max = Len_Enc_Data/1000;

   StartD = (hei_buf[0]); //метка начала второго оборота
   StopD = hei_buf[NumHei-1]; //метка начала последнего оборота

   for(i=StartD;i<StopD;i++){

      Tsr = 0;

      if(FlagTableLenta){
        for(j=0;j<NumTOb;j++){
           if(((i+j-EncNumMetok)!=hei_buf[CntObLenta]) && (i+j-EncNumMetok)!=hei_buf[CntObLenta+1]) Tsr += data_buf_prep[1][i+j-EncNumMetok]*TableLenta[CntTableLenta];   //вычисляем среднее
        }
        etime = data_buf_prep[1][i]*TableLenta[CntTableLenta];
        if(i!=hei_buf[CntObLenta]){
           CntTableLenta++;
           if((CntTableLenta==EncNumMetok) || (i==hei_buf[CntObLenta])) CntTableLenta = 0;
        }
      }
      else{
        for(j=0;j<NumTOb;j++){
           if(((i+j-EncNumMetok)!=hei_buf[CntObLenta]) && (i+j-EncNumMetok)!=hei_buf[CntObLenta+1]) Tsr += data_buf_prep[1][i+j-EncNumMetok];
        }
        etime = data_buf_prep[1][i];
      }

      Tsr/=(float)NumTOb;
      if(i!=hei_buf[CntObLenta]) Asum += (etime-Tsr)*(Speedd/etime); //синтезируем с пропуском склеек ленты
      buf_ob[CntT] = Asum;
      CntT++;

      if(i==hei_buf[CntObLenta]) CntObLenta++; //сквозной счетчик меток оборотов (склеек ленты)

      if(i==hei_buf[CntObt*Tact]){ //определяем конец оборота с учетом тактности

        if(CntT==NumTOb){
            for(j=0;j<CntT;j++){
              data_buf_prep[0][CntD+hei_buf[0]] = buf_ob[j]*1000.0;
              CntD++;
            }
            CntOb++;
        }else{
           if(CntOb<1000) Form1->ListBox1->Items->Add("Игнор. Об. несовп-е кол-ва меток-" + IntToStr(CntT));
        }

        CntObt++;
        CntT = 0;
        Asum = 0.0;

        if(i%1000==0) Form1->ProgressBar1->Position+=1;

      }
   }

   Form1->ListBox1->Items->Add("MaxMetok: "+IntToStr(MaxMetok));
   Form1->ListBox1->Items->Add("MinMetok: "+IntToStr(MinMetok));

return CntOb;
}


int getTObor(int Num){
int i,j;
int CntOb = 0;
int CntDv = 0;
int CntT = 0;
float Tsum = 0;
float SumTimeOb = 0;

   Form1->ProgressBar1->Position = 0;
   Form1->ProgressBar1->Max = Num/1000;

   for(i=EncNumMetok;i<Num-EncNumMetok;i++){

      Tsum+=data_buf_prep[1][i];
      CntT++;

      if(CntT==EncNumMetok){

         hei_buf[CntOb] = i;
         time_buf_dv[CntDv] = 60.0/Tsum;      //обор/мин
         Tsum = Tsum*1000.0;
         time_buf[CntOb] = Tsum;

         if(MaxTimeOb<Tsum) MaxTimeOb=Tsum;
         if(MinTimeOb>Tsum) MinTimeOb=Tsum;
         SumTimeOb+=Tsum;

         CntT = 0;
         Tsum = 0;
         if((CntOb%NOborFix)==0) CntDv++;
         CntOb++;
      }

      if(i%1000==0) Form1->ProgressBar1->Position+=1;
   }

   MeanTimeOb = SumTimeOb/CntOb;

return CntOb;

}

/*
void SubPorogTLenta(int Num){
  for(i=0;i<Num;i++){
     data_buf_prep[1][i]
  }
}
*/

int getTOborLenta(int Num){
int i,j;
int St = (LENWINP+1)/2;
int CntOb = 0;
int CntDv = 0;
int CntT = 0;
float Tsum = 0.0;
float SumTimeOb = 0;
int CntTableLenta = 0;
bool FlPervOb=false;
float PorTOb = StrToFloat(Form1->LabeledEdit28->Text);
float Sample, Mediana;

   Form1->ProgressBar1->Position = 0;
   Form1->ProgressBar1->Max = Num/1000;

   for(i=0;i<Num;i++){

      Tsum+=data_buf_prep[1][i];

      CntT++;
/*
      Mediana = ((EncPorogT[i]/1000.0)/PorTOb);
      Sample = data_buf_prep[1][i] - Mediana;
      if(Sample<0) Sample = -Sample;
      Sample+=Mediana;
*/
      Sample = data_buf_prep[1][i];

      if(Sample>(EncPorogT[i]/1000.0)){ //если больше порога

        if(FlPervOb==true){   //пропускаем первый оборот    НАДО ОБЯЗАТЕЛЬНО ПРОПУСТИТЬ ПЕРВЫЙ ОБОРОТ!

          hei_buf[CntOb] = i;
          time_buf_dv[CntDv] = 60/Tsum;      //обор/мин
          Tsum = Tsum*1000.0;
          time_buf[CntOb] = Tsum;

          if(MaxTimeOb<Tsum) MaxTimeOb=Tsum;
          if(MinTimeOb>Tsum) MinTimeOb=Tsum;
          SumTimeOb+=Tsum;

          CntT = 0;
          Tsum = 0.0;
          CntTableLenta = 0;
          if((CntOb%NOborFix)==0) CntDv++;
          CntOb++;
        }
        FlPervOb=true;
        if(i%1000==0) Form1->ProgressBar1->Position+=1;
      }
   }

   MeanTimeOb = SumTimeOb/CntOb;

return CntOb;

}

void __fastcall TForm1::BitBtn1Click(TObject *Sender){
  ListBox1->Items->Add("Синтез сигнала и опред-ие кол-ва об");

  if(RadioGroup5->ItemIndex==0){
     NumObEnc = Syntez_Signal_Enc();
     NumHei  = getTObor(NumObEnc*EncNumMetok*NOborFix);
  }
  else{
     NumHei = getTOborLenta(Len_Enc_Data);
     Syntez_Signal_Enc_Lenta();
     View_Ob_Enc();
  }

  //ListBox1->Items->Add("Синтез завершен");
  //ListBox1->Items->Add("Отрисовка");
  //View_tStrob_Enc(NumHei);

  ViewSigEnc();
  SpeedButton4->Enabled = true;
}

void View_Ob_Enc(){
int i;
  Form1->Chart6->Series[0]->Clear();
  Form1->Chart6->Axes->Bottom->Maximum = NumHei;
  for(i=0;i<NumHei;i++){
    Form1->Chart6->Series[0]->AddY(time_buf[i]);
  }
  Form1->Chart6->Repaint();
}


long __fastcall GetEncNumSampleFile(){
long Ld = 0;
int d_ch;

   ifstream EData(DFile.c_str(), ios::in|ios::binary);

   while(!EData.eof()){

      EData.read((char*)&d_ch,sizeof(d_ch));

      if(EData.eof()){
          EData.close();
          break;
      }

     Ld++;
     if((Ld%10000)==0) Form1->ProgressBar1->Position++;
   }

   EData.close();

  return Ld;
}

int __fastcall GetTEncFromFile(){
int i,j;
int cntT = 0;
int tp1 = 0;
int tp2 = 0;
float etime = 0;
float Tsr = 0;
bool DetP = false;
bool FlOb = false;
long ns = 0;
int d_ch;
float sample;
float buf_ob[128000];
int CntBufP = 0;
int CntBufD;
float SrObLast = 0;
float SrObFirst = 0;
float DeltaSr;
int cntOb = 0;
int cntObor = 0;
int cnt_err_Obor = 0;
int cnt_obor_ok = 0;
int err_enc_imp = 0;
float Tact = 4/2;
int Ns;
bool ErrOb;
float MaxTi = -10000000.0;
float MinTi = 10000000.0;
int StartData, StopData;
char cbuf[16] = {0};
int stp;
int cnt_metok;
float Tsum = 0.0;

   EncNumMetok = StrToInt(Form1->LabeledEdit20->Text);
   PorogEnc = StrToFloat(Form1->LabeledEdit24->Text);
   FdEnc = StrToFloat(Form1->LabeledEdit23->Text);
   DtEnc = 1.0/FdEnc;
   float PorErrorOb = StrToFloat(Form1->LabeledEdit25->Text);
   Ns = (EncNumMetok*Tact)/4;

   Fl_OK = false; //сбрасываем флаг выставления границ обработки
   StartData = StrToInt(Form1->LabeledEdit11->Text); //начало границы данных обработки
   StopData = StrToInt(Form1->LabeledEdit13->Text);  //конец границы данных обработки

if(fl_enc_hard==0){ //если это не аппаратный енкодер

   ifstream EData(DFile.c_str(), ios::in|ios::binary);

   //смещаемся на указанный начало границы обработки данных
   for(i=0;i<StartData;i++){
     EData.read((char*)&d_ch,sizeof(d_ch));
   }

   for(ns=StartData;ns<StopData-NPorog;ns++){

      EData.read((char*)&d_ch,sizeof(d_ch));
      sample = ((float)d_ch*AbsolutEnc)-NormEnc;;

      if(EData.eof()){
          EData.close();
          break;
      }

      if(DetP==false){

        if(sample>PorogEnc){

          DetP = true;

          tp2 = ns;
          etime = (float)(tp2-tp1)*DtEnc;
          tp1 = ns;

          buf_ob[cntOb] = etime;
          cntOb++;

   //----------- однотипный блок кода -----------
          if(cntOb==EncNumMetok*Tact){

             cntOb = 0;
             ErrOb = false;
             MaxTi = -10000000.0;
             MinTi = 10000000.0;

             for(i=0;i<EncNumMetok*Tact;i++){
                if(MaxTi<buf_ob[i]) MaxTi = buf_ob[i];
                if(MinTi>buf_ob[i]) MinTi = buf_ob[i];
             }

             DeltaSr = MaxTi-MinTi;
             DeltaSr = (DeltaSr*100)/MaxTi;
             if(DeltaSr>PorErrorOb){
                ErrOb = true;
                cnt_err_Obor++;
                err_enc_imp+=EncNumMetok*Tact;
             }

             if(ErrOb==false){
                for(i=0;i<EncNumMetok*Tact;i++) data_buf_prep[1][cntT+i] = buf_ob[i];
                cntT+=EncNumMetok*Tact;
             }
             cntObor++;

          }
     //----------- однотипный блок кода -----------     
        }
      }
      else{
        if(sample<PorogEnc){
          DetP = false;
        }
      }

      if((cntT+EncNumMetok*Tact)>NumSampleEnc) break;
      if(ns%10000==0) Form1->ProgressBar1->Position+=1;
   }

   EData.close();
}
else{

if(Form1->CheckBox24->Checked) DecimalSeparator = '.';

   ifstream EData(DFile.c_str(), ios::in);

   while(!EData.eof()){

      EData.getline(cbuf, sizeof(cbuf));
      etime = StrToFloat(cbuf)/1000000.0;

      if(etime>=0){

        buf_ob[cntOb] = etime;
        cntOb++;
        Tsum+=etime;
      //----------- однотипный блок кода -----------
          if(cntOb==EncNumMetok*Tact){

             hei_buf[cntObor] = cnt_metok;
             time_buf[cntObor] = Tsum;

             cntOb = 0;
             ErrOb = false;
             MaxTi = -10000000.0;
             MinTi = 10000000.0;

             for(i=0;i<EncNumMetok*Tact;i++){
                if(MaxTi<buf_ob[i]) MaxTi = buf_ob[i];
                if(MinTi>buf_ob[i]) MinTi = buf_ob[i];
             }
             
             if(MaxTi==0) MaxTi = 0.0000001;

             DeltaSr = MaxTi-MinTi;
             DeltaSr = (DeltaSr*100)/MaxTi;

             if(DeltaSr>PorErrorOb){
                ErrOb = true;
                cnt_err_Obor++;
                err_enc_imp+=EncNumMetok*Tact;
             }
             else{
                stp = 1;
             }

             if(ErrOb==false){
                for(i=0;i<EncNumMetok*Tact;i++) data_buf_prep[1][cntT+i] = buf_ob[i];
                cntT+=EncNumMetok*Tact;
                cnt_obor_ok++;
             }
             cntObor++;
             Tsum = 0;
          }

          cnt_metok++;
      //------------------------------------------
      }
   }
   EData.close();
}

   DecimalSeparator = ',';

   Form1->ListBox1->Items->Add("Всего об: "+IntToStr(cntObor));
   Form1->ListBox1->Items->Add("Всего имп: "+IntToStr((int)(cntObor*EncNumMetok*Tact)));

   Form1->ListBox1->Items->Add("Ошибка об: "+IntToStr(cnt_err_Obor));
   Form1->ListBox1->Items->Add("Игнор имп: "+IntToStr(err_enc_imp));

   Form1->ListBox1->Items->Add("Обработано об: "+IntToStr(cnt_obor_ok));
   Form1->ListBox1->Items->Add("Обработано имп: "+IntToStr(cntT));

   return cntT;
}


int __fastcall GetTEncFromFileLenta(){
int i,j;
int cntT = 0;
int tp1 = 0;
int tp2 = 0;
float etime = 0;
float Tsr = 0;
bool DetP = false;
long ns = 0;
int d_ch;
float sample, tsmp;
float buf_ob[128000];  //буфер оборота

float Filtr_buf[5];  //буфер фильтра сглаживания
int CntFiltr = 0;
int NFiltr = 5;

float buf_porog[1024];  //буфер окна формирования порога скользящим средним
int CntBufP = 0;
int CntBufD;

float SrObLast = 0;
float SrObFirst = 0;
float DeltaSr;
int cntOb = 0;
int cntObor = 0;

float Tact = 4/2;
int Ns;
bool ErrOb;
float MaxTi = -10000000.0;
float MinTi = 10000000.0;
int StartData, StopData;
int St = (LENWINP+1)/2;

   EncNumMetok = StrToInt(Form1->LabeledEdit20->Text);
   PorogEnc = StrToFloat(Form1->LabeledEdit24->Text);
   FdEnc = StrToFloat(Form1->LabeledEdit23->Text);
   DtEnc = 1.0/FdEnc;
   float PorErrorOb = StrToFloat(Form1->LabeledEdit25->Text);
   Ns = (EncNumMetok*Tact)/4;

   Fl_OK = false; //сбрасываем флаг выставления границ обработки
   StartData = StrToInt(Form1->LabeledEdit11->Text); //начало границы данных обработки
   StopData = StrToInt(Form1->LabeledEdit13->Text);  //конец границы данных обработки
   NPorog = StrToInt(Form1->LabeledEdit26->Text);    //длина окна порога
   Koeff = StrToFloat(Form1->LabeledEdit27->Text);
   CntBufD = NPorog/2;

   ifstream EData(DFile.c_str(), ios::in|ios::binary);

   //смещаемся на указанный начало границы обработки данных
   for(i=0;i<StartData;i++){
     EData.read((char*)&d_ch,sizeof(d_ch));
   }

   //первоначальное заполнение окна фильтра сглаживания
   for(i=0;i<NFiltr;i++){
      EData.read((char*)&d_ch,sizeof(d_ch));
      tsmp = ((float)d_ch*AbsolutEnc)-NormEnc;
      Filtr_buf[i] = tsmp;
   }
   //первоначальное заполнение окна формирования порога
   for(i=0;i<NPorog;i++){
     tsmp = 0;
     for(j=0;j<NFiltr;j++) tsmp+=Filtr_buf[j];
     tsmp/=NFiltr;
     buf_porog[i] = tsmp;

     EData.read((char*)&d_ch,sizeof(d_ch));
     tsmp = ((float)d_ch*AbsolutEnc)-NormEnc;
     Filtr_buf[CntFiltr] = tsmp;
     CntFiltr++;
     if(CntFiltr==NFiltr) CntFiltr = 0;
   }

   for(ns=StartData;ns<StopData-NPorog-NFiltr;ns++){

      if(Form1->CheckBox14->Checked){
        PorogEnc = 0;
        for(i=0;i<NPorog/KDecim;i++) PorogEnc+=buf_porog[i*KDecim];
        PorogEnc = (PorogEnc/(NPorog/KDecim))*Koeff;
      }

      sample = buf_porog[CntBufD];

      CntBufP++;
      CntBufD++;
      if(CntBufP==NPorog) CntBufP = 0;
      if(CntBufD==NPorog) CntBufD = 0;

      EData.read((char*)&d_ch,sizeof(d_ch));
      tsmp = ((float)d_ch*AbsolutEnc)-NormEnc;
      Filtr_buf[CntFiltr] = tsmp;
      CntFiltr++;
      if(CntFiltr==NFiltr) CntFiltr = 0;

      tsmp = 0;
      for(j=0;j<NFiltr;j++) tsmp+=Filtr_buf[j];
      tsmp/=NFiltr;
      buf_porog[CntBufP] = tsmp;

      if(EData.eof()){
          EData.close();
          break;
      }

      if(DetP==false){
        if(sample>PorogEnc){
          DetP = true;
          tp2 = ns;
          etime = (float)(tp2-tp1)*DtEnc;
          tp1 = ns;
          if(cntT>0) data_buf_prep[1][cntT-1] = etime;
          cntT++;
        }
      }
      else{

        if(sample<PorogEnc){
          DetP = false;
        }
      }

      if(ns%10000==0) Form1->ProgressBar1->Position+=1;
   }

   EData.close();

   for(i=0;i<cntT-St-1;i++) data_buf_prep[1][i] = data_buf_prep[1][St+i];

   return cntT-1;
}


void __fastcall PorogTEnc(){
int i,j;
float BufWin[LENWINP];
float PorogT;
int CntWin = 0;
float KPT = StrToFloat(Form1->LabeledEdit28->Text);
  //инициализируем буфер формирования порога
  for(j=0;j<LENWINP;j++) BufWin[j] = data_buf_prep[1][j];

  for(i=LENWINP;i<Len_Enc_Data-LENWINP;i++){
     PorogT = 0;
     for(j=0;j<LENWINP;j++) PorogT+=BufWin[j];
     PorogT = ((PorogT/LENWINP)*KPT)*1000.0;
     EncPorogT[i-LENWINP] = PorogT;
     BufWin[CntWin] = data_buf_prep[1][i];
     CntWin++;
     if(CntWin==LENWINP) CntWin = 0;
  }
}

void __fastcall ViewTEnc(){
int i;
int St = (LENWINP+1)/2;
   Form1->Chart2->Series[0]->Clear();
   Form1->Chart2->Series[1]->Clear();

   Form1->Chart2->Axes->Bottom->Maximum = Len_Enc_Data;

   for(i=0;i<Len_Enc_Data-LENWINP;i++){
      Form1->Chart2->Series[0]->AddY(data_buf_prep[1][i]*1000.0);
      Form1->Chart2->Series[1]->AddY(EncPorogT[i]);
   }
}

void __fastcall ViewSigEnc(){
int i;

   Form1->Chart1->Series[0]->Clear();
   Form1->Chart1->Axes->Bottom->Maximum = Len_Enc_Data-EncNumMetok;

   for(i=0;i<Len_Enc_Data-EncNumMetok;i++){
      Form1->Chart1->Series[0]->AddY(data_buf_prep[0][i]);
   }

   if(Form1->CheckBox16->Checked){
      Form1->Chart2->Series[1]->Clear();

      for(i=0;i<Len_Enc_Data-EncNumMetok;i++){
         Form1->Chart2->Series[1]->AddY(EncPorogT[i]*1000.0);
      }
   }

}
//---------------------------------------------------------------------------


void ReadEncView(int offs){
int i,j;
int d_ch;
float sample;

   NPorog = StrToInt(Form1->LabeledEdit26->Text);    //длина окна порога
   Koeff = StrToFloat(Form1->LabeledEdit27->Text);
   PorogEnc = StrToFloat(Form1->LabeledEdit24->Text);

   ifstream EData(DFile.c_str(), ios::in|ios::binary);

   Form1->Chart2->Series[0]->Clear();
   Form1->Chart2->Series[1]->Clear();
   Form1->Chart2->Axes->Bottom->Maximum = NumEncView;

   for(i=0;i<offs*NumEncView;i++){
       EData.read((char*)&d_ch,sizeof(d_ch));
   }

   for(i=0;i<NumEncView;i++){
      EData.read((char*)&d_ch,sizeof(d_ch));
      sample = ((float)d_ch*AbsolutEnc)-NormEnc;
      data_buf_encod[i] = sample;
   }

   EData.close();

 if(Form1->CheckBox14->Checked){

   for(i=0;i<NumEncView-NPorog;i++){
      sample = 0;
      for(j=0;j<NPorog/KDecim;j++) sample+=data_buf_encod[i+j*KDecim];
      EncPorog[i] = (sample/(NPorog/KDecim))*Koeff;
   }
 }
 else{
      for(i=0;i<NumEncView-NPorog;i++) EncPorog[i] = PorogEnc;
 }
   for(i=NPorog/2;i<NumEncView;i++){
      Form1->Chart2->Series[0]->AddY(data_buf_encod[i]);
   }

   for(i=0;i<NumEncView-NPorog;i++){
     Form1->Chart2->Series[1]->AddY(EncPorog[i]);
   }

}


void __fastcall TForm1::Button15Click(TObject *Sender){

  ListBox1->Items->Add("Определение кол-ва сэмплов");
//  NumSampleEnc = GetEncNumSampleFile();
  //NumSampleEnc = 40000000;
  ListBox1->Items->Add("Кол-во сэмплов: "+IntToStr(NumSampleEnc));
  ListBox1->Items->Add("Обнаружение импульсов");
  ProgressBar1->Position = 0;
  ProgressBar1->Max = NumSampleEnc/10000;

  if(RadioGroup5->ItemIndex==0){
    Len_Enc_Data = GetTEncFromFile();
  }
  else{
    Len_Enc_Data = GetTEncFromFileLenta();
    PorogTEnc();
  }

  Len_Data = Len_Enc_Data;
  Len_Data_View = Len_Data;
  ViewTEnc();
  FlAnaliz = true;
  BitBtn1->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RadioGroup4Click(TObject *Sender)
{
if(RadioGroup4->ItemIndex==0){
  TabSheet7->Enabled = false;
  PageControl1->TabIndex = 0;
  TabSheet1->Show();
  RadioButton1->Enabled = true;
  RadioButton1->Checked = true;


}
else{
  TabSheet7->Enabled = true;
  PageControl1->TabIndex = 2;
  TabSheet7->Show();
  RadioButton1->Enabled = false;
  RadioButton2->Checked = true;
  RadioButton1->Checked = false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup5Click(TObject *Sender)
{
if(RadioGroup5->ItemIndex==0){
  LabeledEdit25->Text = "10";
  CheckBox14->Checked = false;
}
else{
  LabeledEdit25->Text = "100";
  CheckBox14->Checked = true;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
/*
    OborUsr = Calc_Garm_Usr();

    if(RadioGroup2->ItemIndex==1){
       ViewGarm();
    }
    else{
       ViewGarmUsr();
    }
    RadioButton5->Enabled = true;
    CheckBox5->Enabled = true;
    RadioButton5->Checked = true;
    //CheckBox5->Checked = true;

    TrackBar2->Position = 0;
    TrackBar2->Max = OborUsr;
    UpDown3->Position = 0;
    UpDown3->Max = OborUsr;
*/            
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Chart3DblClick(TObject *Sender)
{
   double pX,pY;
   int St;

if((GetAsyncKeyState(18)<<1)!=0){
       Chart3->CopyToClipboardMetafile(true);
}
else{
   if(NumHeiObr>5){
      Chart3->Series[0]->GetCursorValues(pX,pY);
      if(SelDelOb==false){
         Edit1->Text = IntToStr((int)(pX));
         SelDelOb=true;
      }
      else{
         St = StrToInt(Edit1->Text);
         if(St<(int)pX){
           SelDelOb=false;
           Edit2->Text = IntToStr((int)(pX));
         }
      }
   }
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Chart9MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 double pX,pY;
 float tob, obm; 
 int i,k;
 int NumO = 0;
 int a,b,delta;

 if(!CheckBox10->Checked){

    if((Len_File_Data>BlockZoomView*2) && (pX>0)){

      Series31->GetCursorValues(pX,pY);  // <-- get values under mouse cursor
      Chart6->Series[0]->Clear();

      k = (int)pX;
      a = hei_buf[k];
      b = hei_buf[k+1];
      delta = b-a;
      tob = delta*Tfd;
      obm = 60.0/tob;
      Label20->Caption = "№ Об: " + IntToStr(k)+ "; Время Об:" + FloatToStrF(tob, ffGeneral, 4,4)+"; Об/мин: " + FloatToStrF(obm, ffGeneral, 4,2);

      for(i=0;i<delta;i++) Chart6->Series[0]->AddY(data_buf_prep[0][a+i]);

    }
 }
}
//---------------------------------------------------------------------------

void __fastcall DelOborot(int starto, int stopo){
 int i;
 int start_s, stop_s;
 //определяем диапазон сэмплов по номерам диапазонов оборотов

// for(i=0;i<NumErrD;i++){

// }

}

void __fastcall TForm1::Button17Click(TObject *Sender)
{
int i,j;
int start_nob, stop_nob;

  if(!FlSelect){

    Button17->Enabled = false;
    //АЛГОРИТМ УДАЛЕНИЯ ПЛОХИХ ОБОРОТОВ И ПЕРЕХОДОВ

    start_nob = ObErr[0];

    if(NumErrD>1){

       for(i=0;i<NumErrD;i++){

         if(i<(NumErrD-1) ){

            if((ObErr[i]-ObErr[i+1])>2){

              stop_nob = ObErr[i];
              if(start_nob%2==1) start_nob-=1;
              if(stop_nob%2==1) stop_nob+=1;
              DelOborot(start_nob, stop_nob);
              start_nob = ObErr[i+1];

            }

         }

       }

    }
  }

  int ObErr[MAX_H_ERR];
  int NumErrD = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
   if(!FlSelect){
      FlSelect = true;
   }
   else{
      FlSelect = false;
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
int i,j;
int starto = StrToInt(Edit1->Text);
int stopo = StrToInt(Edit2->Text);
int leno = stopo-starto;

if(NumErrDop==0){
  ListBox2->Clear();
  ListBox2->Items->Add("В списке игнор. об:");
}

//добавляем в список плохих оборотов
for(i=0;i<leno;i++){
  ObErrDop[NumErrDop+i] = starto+i;
  ObErrDopS[NumErrDop+i] = Oboroty_Obr[0][starto+i];
  ListBox2->Items->Add(IntToStr(starto+i));
}

NumErrDop+=leno;
FL_ErrDopOb = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  NumErrDop = 0;
  FL_ErrDopOb = false;
  Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit9KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      Fd = StrToFloat(LabeledEdit9->Text);
      Tfd = 1/Fd;
      ListBox1->Items->Add("Fd = " + FloatToStr(Fd));
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox8Click(TObject *Sender)
{
   View_Ob();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox19Click(TObject *Sender)
{
    if(CheckBox19->Checked){
     ViewMetkiOb();
    }
    else{
      Form1->Chart1->Series[2]->Clear();
      if(RadioGroup4->ItemIndex>0) Form1->Chart2->Series[2]->Clear();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart5DblClick(TObject *Sender)
{
if((GetAsyncKeyState(18)<<1)!=0){
       Chart5->CopyToClipboardMetafile(true);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart4DblClick(TObject *Sender)
{
if((GetAsyncKeyState(18)<<1)!=0){
       Chart4->CopyToClipboardMetafile(true);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1DblClick(TObject *Sender)
{
if((GetAsyncKeyState(18)<<1)!=0){
       Chart1->CopyToClipboardMetafile(true);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart9DblClick(TObject *Sender)
{
if((GetAsyncKeyState(18)<<1)!=0){
       Chart9->CopyToClipboardMetafile(true);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart6DblClick(TObject *Sender)
{
if((GetAsyncKeyState(18)<<1)!=0){
       Chart6->CopyToClipboardMetafile(true);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button23Click(TObject *Sender)
{
   Chart3->Axes->Left->Maximum = Chart3->Axes->Left->Maximum+Chart3->Axes->Left->Maximum/20.0;
   Chart3->Axes->Left->Minimum = Chart3->Axes->Left->Minimum-Chart3->Axes->Left->Maximum/20.0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox20Click(TObject *Sender)
{
if(CheckBox22->Checked){
   Chart3->Axes->Left->Automatic = true;
   Chart3->Axes->Left->AutomaticMaximum = true;
   Chart3->Axes->Left->AutomaticMinimum = true;
}
else{
   Chart3->Axes->Left->Automatic = false;
   Chart3->Axes->Left->AutomaticMaximum = false;
   Chart3->Axes->Left->AutomaticMinimum = false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
   float mx = Chart3->Axes->Left->Maximum - Chart3->Axes->Left->Maximum/20.0;
   float mn = Chart3->Axes->Left->Minimum+Chart3->Axes->Left->Maximum/20.0;

   if(mx>mn){
     Chart3->Axes->Left->Maximum = mx;
     Chart3->Axes->Left->Minimum = mn;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
   float mx = Chart3->Axes->Bottom->Maximum;
   float mn = Chart3->Axes->Bottom->Minimum;
   mx = mx+2.0;
   mn = mn-2.0;
   if(mx>mn){
     Chart3->Axes->Bottom->Maximum = mx;
     Chart3->Axes->Bottom->Minimum = mn;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
   float mx = Chart3->Axes->Bottom->Maximum;
   float mn = Chart3->Axes->Bottom->Minimum;
   mx = mx-2.0;
   mn = mn+2.0;
   if(mx>mn){
     Chart3->Axes->Bottom->Maximum = mx;
     Chart3->Axes->Bottom->Minimum = mn;
   }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::CheckBox13Click(TObject *Sender)
{
  if(CheckBox13->Checked){
    Button28->Enabled = true;
    LabeledEdit20->Enabled = false;
    if(TableNumMetok!=0) FlagTableLenta = true;
    else FlagTableLenta = false;
  }
  else{
    Button28->Enabled = false;
    LabeledEdit20->Enabled = true;
    FlagTableLenta = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
int n = 0;
char cbuf[16] = {0};

   if(Form1->OpenDialog2->Execute()){ //*
      TableLentaFile = OpenDialog2->FileName;

      ifstream inData(TableLentaFile.c_str(), ios::in);

      while(!inData.eof()){
         inData.getline(cbuf, sizeof(cbuf));
         TableLenta[n] = StrToFloat(cbuf);
         n+=1;
      }
      inData.close();
      if(n>1){
        EncNumMetok = n;
        TableNumMetok = n;
        FlagTableLenta = true;
        ListBox1->Items->Add("Таблица меток ленты энкодера");
        ListBox1->Items->Add("Меток в таблице: "+ IntToStr(EncNumMetok));
      }else{
        FlagTableLenta = false;
        ListBox1->Items->Add("Ошибка открытия таблицы меток ленты");
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit20KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      EncNumMetok = StrToInt(LabeledEdit20->Text);
      ListBox1->Items->Add("Меток в таблице: "+ IntToStr(EncNumMetok));
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
   CalcNoborFix();
   ListBox1->Items->Add("Такт двигателя: " + ComboBox1->Text);
}
//---------------------------------------------------------------------------



void CalcNoborFix(){

   KRed = 1.0/StrToFloat(Form1->LabeledEdit10->Text); //коэф. редукции
   TactDv = StrToInt(Form1->ComboBox1->Text);
   int NObor = TactDv/2; // получаем оборотов в зависимости от тактности

   if(NObor==2){
      if(KRed<=0.5){
         NObor = 1;
         KRed = KRed/0.5;
      }
   }
   NOborFix = NObor;
}

void __fastcall TForm1::LabeledEdit10KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      CalcNoborFix();
      ListBox1->Items->Add("Коэф. ред: " + LabeledEdit10->Text);
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit23KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      FdEnc = StrToInt(LabeledEdit23->Text);
      DtEnc = 1.0/FdEnc;
      ListBox1->Items->Add("Fd энкодера: " + IntToStr((int)FdEnc) + " Гц");
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
   TIniFile *Ini = new TIniFile(".\\settings.ini");

   Ini->WriteString("Options->Obrabotka","LabeledEdit1", "123");
   Ini->UpdateFile();

   delete Ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
int i, ng;
//---------- сохранение настроек в INI файл --------------------------------
   TIniFile *Ini = new TIniFile(".\\settings.ini");

  //--- секция основная панель настроек ---------------------------------------
    Ini->WriteString("Options->Main","Type", IntToStr(RadioGroup4->ItemIndex));

    Ini->WriteString("Options->Obrabotka","Porog_ob", LabeledEdit1->Text);
    Ini->WriteString("Options->Obrabotka","Okno_usred", LabeledEdit14->Text);
    Ini->WriteBool("Options->Obrabotka","Avto_Porog", CheckBox4->Checked);

    Ini->WriteString("Options->Enc","Type", IntToStr(RadioGroup5->ItemIndex));
    Ini->WriteString("Options->Enc","Porog", LabeledEdit24->Text);
    Ini->WriteBool("Options->Enc","AvtoPorog", CheckBox14->Checked);
  //---------------------------------------------------------------------------

  //-------- Дополнительно -> Параметры ---------------------------------------
    Ini->WriteString("DopParams->Obrabotka","K_Redukc", LabeledEdit10->Text);
    Ini->WriteString("DopParams->Obrabotka","Tact_Dv", ComboBox1->Text);
    Ini->WriteString("DopParams->Obrabotka","N_Garm", LabeledEdit12->Text);
    Ini->WriteString("DopParams->Obrabotka","Oshibka_ob", LabeledEdit2->Text);
    Ini->WriteBool("DopParams->Obrabotka","En_Oshibka_Ob", CheckBox15->Checked);
    Ini->WriteString("DopParams->Obrabotka","Oshibka_Ampl", LabeledEdit15->Text);
    Ini->WriteBool("DopParams->Obrabotka","En_Det_Err_Ob", CheckBox18->Checked);

    Ini->WriteString("DopParams->Data","Norm_k1", LabeledEdit5->Text);
    Ini->WriteBool("DopParams->Data","En_Norm_k1_Auto", CheckBox2->Checked);
    Ini->WriteString("DopParams->Data","Norm_k2", LabeledEdit6->Text);
    Ini->WriteBool("DopParams->Data","En_Abs_k2", CheckBox3->Checked);
    Ini->WriteBool("DopParams->Data","mV_On", CheckBox1->Checked);
    Ini->WriteString("DopParams->Data","Block_Prokrutki", LabeledEdit16->Text);
    Ini->WriteString("DopParams->Data","Koef_prokrutki", LabeledEdit19->Text);
    Ini->WriteString("DopParams->Data","Razr_ADC", LabeledEdit7->Text);
    Ini->WriteString("DopParams->Data","Fd_ADC", LabeledEdit9->Text);
    Ini->WriteString("DopParams->Data","Min_ADC", LabeledEdit8->Text);
    Ini->WriteString("DopParams->Data","Max_ADC", LabeledEdit4->Text);

    Ini->WriteString("DopParams->Encoder","Kol_Metok", LabeledEdit20->Text);
    Ini->WriteString("DopParams->Encoder","Fd_ADC", LabeledEdit24->Text);
    Ini->WriteString("DopParams->Encoder","ABSOLUT", LabeledEdit21->Text);
    Ini->WriteString("DopParams->Encoder","Norm", LabeledEdit22->Text);
    Ini->WriteString("DopParams->Encoder","Err_Ob%", LabeledEdit25->Text);
    Ini->WriteString("DopParams->Encoder","Okno_Poroga", LabeledEdit26->Text);
    Ini->WriteString("DopParams->Encoder","Koef_Poroga", LabeledEdit27->Text);
    Ini->WriteString("DopParams->Encoder","Koef_PorogaT", LabeledEdit28->Text);

    ng = StrToInt(LabeledEdit12->Text);
    for(i=0;i<ng;i++) Ini->WriteBool("ChartGarm",IntToStr(i), CheckListBox1->Checked[i]);
  //---------------------------------------------------------------------------

   Ini->UpdateFile();

   delete Ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit29KeyPress(TObject *Sender, char &Key)
{
   if(Key==13){
      EncNumMetokUsred = StrToInt(LabeledEdit29->Text);
      ListBox1->Items->Add("Меток усреднения: "+ IntToStr(EncNumMetokUsred));
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button30Click(TObject *Sender)
{
int i;
AnsiString Nfile1;
FILE* out = fopen("D:\out_enc.dat", "w+");

for(i=0;i<Len_Enc_Data;i++){
    fprintf(out,"%f\n", data_buf_prep[1][i]*1000000.0);
}

fclose(out);

}
//---------------------------------------------------------------------------

