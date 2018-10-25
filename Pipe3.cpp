#include <stdio.h> //Thu vien xuat nhap chuan//
#include <unistd.h> //Khai bao su dung Pipe va mot so ham cua Linux//
#include <stdlib.h> //Cac ham chuan cua Linux//
#include <sys/types.h>//
#include <math.h> //Thu vien toan hoc//
#include <string.h> //Khai bao su dung chuoi//
#include <stack>
using namespace std;
//err: phat hien la sang dong hay chua; err1:phat hien dau () hop le; err2: ki tu dau, cuoi k dc la toan tu;err3 la de k co 2 toan tu ke nhau
//dem1:xem thu toan tu dang xet la dau tien hay k; dem2: dem so ki tu doc ; dem2Old: phu de xet co 2 toan tu ke nhau k
int err=0, err1=0, err2=0, dem1=0, dem2=0, dem2Old=-1;
char str[100],str1[10];     //mang char str do dai 100 ; mang char str1 do dai 10
char ch,gan,ch1, chOld, chOld1=' ', chCon;            //hai con tro

stack <char> stack1, stack2, stack3;

void lamRongStack3(){
    while( !stack3.empty() ){
        stack3.pop();
    }
}

void OppositeStack2(){
    char fkitu;
    stack <char> fstack1, fstack2;
    while( !stack2.empty() ){
        fkitu = stack2.top();
        stack2.pop();
        fstack1.push(fkitu);
    }

    while( !fstack1.empty() ){
        fkitu = fstack1.top();
        fstack1.pop();
        fstack2.push(fkitu);
    }

    while(!fstack2.empty()){
        fkitu = fstack2.top();
        fstack2.pop();
        stack2.push(fkitu);
    }
}

char sothanhkitu(int so){
    char kq;
    switch(so){
        case 0:{
            kq='0';
            break;
        }
        case 1: {
            kq='1';
            break;
        }
        case 2:{
            kq='2';
            break;
        }
        case 3:{
            kq='3';
            break;
        }
        case 4:{
            kq='4';
            break;
        }
        case 5:{
            kq='5';
            break;
        }
        case 6:{
            kq='6';
            break;
        }
        case 7:{
            kq='7';
            break;
        }
        case 8:{
            kq='8';
            break;
        }
        case 9:{
            kq='9';
            break;
        }
    }
    return kq;
}

void OppositeStack1(){
    char fkitu;
    stack <char> fstack1, fstack2;
    while( !stack1.empty() ){
        fkitu = stack1.top();
        stack1.pop();
        fstack1.push(fkitu);
    }

    while( !fstack1.empty() ){
        fkitu = fstack1.top();
        fstack1.pop();
        fstack2.push(fkitu);
    }

    while(!fstack2.empty()){
        fkitu = fstack2.top();
        fstack2.pop();
        stack1.push(fkitu);
    }
}

void tachIntRoiPushVoStack(int fkq ){
    int flagDuong;
    stack <int> fstack3;

    if(fkq < 0){
        flagDuong = 0;
        fkq = fkq*(-1);
    }else{
        flagDuong = 1;
    }
    int fn1=fkq;
    int fso;
    char fkituso;

    while(fn1>0){
        fso = fn1%10;
        //printf("%d", fso);
        fstack3.push(fso);
        fn1 = fn1/10;
    }

    if(flagDuong == 0){
        stack2.push('-');
    }

    while(!fstack3.empty()){
        fso = fstack3.top();
        fstack3.pop();
        //printf("%d-", fso);
        fkituso = sothanhkitu(fso);
        //putchar(fkituso);

        stack2.push(fkituso);
    }
}

int xuly(int fi, int fa[])
{
    int ftam=0, fn =fi, fj;
    for (fj=0;fj<=(fi-1);fj++)
    {
        ftam=ftam+(fa[fj]*(pow(10,(fn-1))));
        fn--;
    }

    return (ftam);
}

int tinhBieuThucTrongStackDonGian(stack <char> fstack2) {
    int fa[30], fm[3];
    int fdem1=0,fdem2=0;
    int fk=0,fi=0, fkq=0;
    char fgan='n', fchCon, fchOld=' ';
     //duyet het cac phan tu troong stack2, roi tinh toan theo thuat toan ban dau (k validate)
    while( !fstack2.empty() ) {
        //lay ki tu do ra luu vo bien chCon, pop no ra luon khoi stack2
        fchCon = fstack2.top();
        //pop no ra luon khoi stack2
        fstack2.pop();

        if((fchCon=='0')||(fchCon=='1')||(fchCon=='2')||(fchCon=='3') ||(fchCon=='4') ||(fchCon=='5') ||(fchCon=='6') ||(fchCon=='7') ||(fchCon=='8')||(fchCon=='9') ) //khog phai ki tu +, -, *, /
        {
             //chuyen ki tu do ve double,sau do -48, sau do chuyen ve kieu char, luu vao str
            fa[fi] = int (fchCon);
            fa[fi] = (fa[fi] - 48);
            //printf("a[%d] la : %d", fi, fa[fi]);
                   //gcvt(a[i],4,str);      //chuyen double thanh char
            fi++;                           //tang len de luu ki tu, cho lan duyet ki tu tiep theo(beacause while)
        }
        else if((fchCon=='+')||(fchCon=='-'))  //Xu li khi gap ki tu thuc hien phep tinh: +-/*
        {
            fdem1 = fdem1 + 1;
            if(fdem1==1){
                fgan = fchCon;
                fm[fk] = xuly(fi, fa );  //k ban dau = 0;
                //printf("fm[%d] la : %d", fk, fm[fk]);
                fi=0;
                fk=fk+1;
            }
            else if(fdem1==1 && fdem2 == 1){ //truog hop toan tu xuat hien dau tien, cua chuoi
                fgan = fchCon;
                fm[fk] = 0;
                fi=0;
                fk=fk+1;
            }
            else if(fdem1 !=1 && fdem2 != 1 && (fchOld=='+' || fchOld=='-')){
                 fm[fk] = 0;  //k ban dau = 0;
                 fi=0;
                 switch(fchCon)
                {
                    case '+':
                    {
                        if(fchOld=='-'){

                        }else{

                        }
                        break;
                    }
                    case '-':
                    {

                        if(fchOld=='-'){
                            fkq=fm[fk-1]+fm[fk];
                            fm[fk-1] = fkq;
                            fm[fk] = 0;
                            fgan = '+';
                        }else{
                            fkq=fm[fk-1]+fm[fk];
                            fm[fk-1] = fkq;
                            fm[fk] = 0;
                            fgan = '-';
                        }

                        break;
                    }

                 }


            }

            else{
                //strcpy(str," ");
                //strcpy(str,&gan);
                fm[fk] = xuly(fi, fa);  //k ban dau = 0;
                 fi=0;
                switch(fgan)
                {
                    case '+':
                    {
                        //strcpy(str,"=");
                        fkq=fm[fk-1]+fm[fk];

                        fm[fk-1] = fkq;
                        fm[fk] = 0;
                        break;
                    }
                    case '-':
                    {
                        //strcpy(str,"=");
                        fkq=fm[fk-1]-fm[fk];

                        fm[fk-1] = fkq;
                        fm[fk] = 0;
                        break;
                    }

                 }

                fgan = fchCon;
                //printf("toantu la:");putchar(fgan);

            }

        }
        else if((fchCon==' '))
        {
            //khong xu li
        }
        else{
            break;
        }

        fchOld = fchCon;

    }

    fkq=0;
    //strcpy(str,"=");
    //strcpy(str1," ");
    fm[fk]=xuly(fi, fa);
    //printf("fm cuoi cung: fm[%d] la : %d", fk, fm[fk]);
    switch(fgan)
    {
        case '+':
        {
            //strcpy(str,"=");
            fkq=fm[fk-1]+fm[fk];
            break;
        }
        case '-':
        {
            //strcpy(str,"=");
            fkq=fm[fk-1]-fm[fk];
            break;
        }
        case 'n':
        {
            //strcpy(str,"=");
            fkq=fm[fk];
            break;
        }

    }
    return fkq;
}

/* Ham tinh gia tri bieu thu cphuc tap, chua trong stack KHONG VALIDATE, tuc la Chuoi CHUAN ROI */
int tinhBieuThucTrongStackPhucTap(){

    char fch, fchOld, fchCon;
    int kq;
    while ( !stack1.empty() ) // KHi stack chua rong //
    {
         fch = stack1.top();
         stack1.pop();
         //putchar(fch);
         //printf("\n");
        //dem2 = dem2+1;
        //if(ch!=10)                          //Neu chua xuong dong // Dang trong 1 dong
        //{

             fchOld = fch;

            /*????????De nghi dung else if  de Validate chinh xac hon*/
            if((fch=='0')||(fch=='1')||(fch=='2')||(fch=='3') ||(fch=='4') ||(fch=='5') ||(fch=='6') ||(fch=='7') ||(fch=='8')||(fch=='9') ) //khog phai ki tu +, -, *, /
            {
                  /* Gap ki tu so thi push vo stack 2*/
                  stack2.push(fch);
            }

            else if((fch=='+')||(fch=='-'))  //Xu li khi gap ki tu thuc hien phep tinh: +-/*
            {
                 /* Gap ki tu toan tu thi push vo stack 1 */
                  stack2.push(fch);
            }
            else if( (fch=='(')||(fch==')') )
            {
                    //xu li
                    if(fch=='('){
                        /* Day mo ngoac vo stack2*/
                        stack2.push(fch);
                    }else{ //gap dau dong ngaoc

                        /*THUAT TOAN KHI GAP DAU DONG NGOAC*/
                        /*Khong day vo stack lam chi nua, pop stack1 ra, dong thoi push vo stack2, cho den khi gap ki tu '(', thi cung pop luon
                            sau khi pop no,()nhung k dua vo stack2)
                        */

                        //printf("In stack2:"); printStack2();printf("\n");

                        while( !stack2.empty() ){
                            fchCon = stack2.top();

                            if( fchCon != '(' ){
                                //pop ki tu do ra khoi satck1
                                stack2.pop();
                                //push ki tu do vo stack2
                                stack3.push(fchCon);
                            }else if (fchCon == '('){
                                //pop ki tu mo nngoac do ra khoi satck1
                                stack2.pop();

                                //duyet het cac phan tu troong stack2, roi tinh toan theo thuat toan ban dau(k validate)

                                //printf("In stack3:"); printStack3();printf("\n");

                                kq = tinhBieuThucTrongStackDonGian(stack3);
                                lamRongStack3();

                                /*  chuyen int kq, thanh cac ki tu thanh phan roi day vo stack1
                                */
                                tachIntRoiPushVoStack(kq);

                                break;

                            }

                        }


                    }
            }
            else if((fch==' '))
            {

            }
            else
            {

            }

        }

         /*
          PHAN TINH TONG SOT LAI TRONG STACK2, thuat toan thi nhu stack3 thoi
        */
        kq = 0;
        //printf("stack2 final:"); printStack2(); printf("\n");
        OppositeStack2();
        //printf("stack2 final sau nghich:"); printStack2(); printf("\n");
        kq = tinhBieuThucTrongStackDonGian(stack2);
        return kq;
}


void do_parent(int pipe_vao[], int pipe_ra[])//Ham dieu khien tien trinh cha doc du lieu//
{
    int rc,dong=0;
    close(pipe_vao[1]);//Dong chuc nang ghi cua tien trinh cha khi gap Pipe doc//
    close(pipe_ra[0]);//Dong chuc nang doc cua tien trinh doc khi gap Pipe ghi//
    //i=0;k=0;
    printf("\n");
        printf("\n");
        printf("        DE TAI HE DIEU HANH: GIAO TIEP CAC TIEN TRINH QUA DUONG ONG PIPE \n");
        printf("                                 Giao Vien Huong Dan : Nguyen Van Nguyen \n");
        printf("                                 Sinh Vien Thuc Hien : Nguyen Van Bay\n");
        printf("                  ====================================\n");

    printf("Moi ban nhap vao mot bieu thuc:");
    while(( ch = getchar() ) > 0) //Ghi trong khi chua gap ky tu ket thuc file//
    {
        rc= write(pipe_ra[1],&ch,1);
        if(rc==-1)
        {
            perror("pipe loi ghi");  //Thong bao loi ghi
            close(pipe_vao[0]);
            close(pipe_ra[1]);
            exit(1);
        }

        rc=read(pipe_vao[0],str,sizeof(str));
        if(rc<=0)
        {
            perror("Thong bao loi"); //Thong bao loi doc//
            perror("\n");
            close(pipe_vao[0]);
            close(pipe_ra[1]);
            exit(1);
        }
        printf("%s", str);
    }

    close(pipe_vao[0]);
    close(pipe_ra[1]);
    exit(0);
}

void do_child(int pipe_vao[], int pipe_ra[])
{
    int rc,z,kt,ki;
    close(pipe_vao[1]);//Dong chuc nang ghi cua tien trinh con khi gap Pipe doc//
    close(pipe_ra[0]);//Dong chuc nang doc cua tien trinh con khi gap Pipe ghi//

     while ( (read(pipe_vao[0],&ch,1)) > 0) //Doc khi chua gap ky tu ket thuc File//
    {
        dem2 = dem2+1;
        if(ch!=10)                          //Neu chua xuong dong// Dang trong 1 dong
        {

             chOld = ch;
             /*Kiem tra su hop le cua chuoi*/
             if (ch == '(') err=err+1;
             else
                  if (ch == ')')
                       err=err-1;

            /*????????De nghi dung else if  de Validate chinh xac hon*/
            if((ch=='0')||(ch=='1')||(ch=='2')||(ch=='3') ||(ch=='4') ||(ch=='5') ||(ch=='6') ||(ch=='7') ||(ch=='8')||(ch=='9') ) //khog phai ki tu +, -, *, /
            {
                  /* Gap ki tu so thi push vo stack 1*/
                  stack1.push(ch);
            }

            else if((ch=='+')||(ch=='-'))  //Xu li khi gap ki tu thuc hien phep tinh: +-/*
            {
                 /* Gap ki tu toan tu thi push vo stack 1 */
                  stack1.push(ch);
                 dem2Old = dem2;

            }
            else if((ch=='(')||(ch==')'))
            {
                    //xu li
                    if(ch=='('){

                         //validate
                        if(chOld1=='0' || chOld1=='1' || chOld1=='2' || chOld1=='3' || chOld1=='4' || chOld1=='5' || chOld1=='6' || chOld1=='7' || chOld1=='8' || chOld1=='9')
                             err2 = 1;

                        /* Day mo ngoac vo stack1*/
                        stack1.push(ch);
                    }else{ //gap dau dong ngaoc
                        //validate
                        if(chOld1=='+' || chOld1=='-' )
                             err2 = 1;
                        /* Day dong ngoac vo stack1*/
                        stack1.push(ch);
                    }
            }
            else if((ch==' '))
            {

            }
            else
            {
                //khong thuoc tap ki tu cho phep
                err2 = 1;
            }

            chOld1 = ch;
        }

        else  //Neu gap ky tu sang dong//
        {
                err1 = 1;
                //valideate ki tu cuoi khong dc la toan tu
                if(chOld == '+' || chOld == '-') err2 = 1;
                //khong nhap chuoi rong
                if(dem2<2) err2=1;

                /*
                  Tinh bieu thuc phuc tap co trong stack1, stack1, hien chua dao nguoc, nen dao nguoc da roi goi ham
                */
                int kq = 0;
                OppositeStack1();
                kq = tinhBieuThucTrongStackPhucTap();
                gcvt(kq,5,str1);
        }

            if (( err != 0 && err1 == 1 ) || ( err2 == 1 && err1 == 1 )) {

                strcpy(str,"Bieu thuc nhap vao khong dung");
                if(dem2 < 2) strcpy(str,"Bieu thuc rong!");

                rc = write(pipe_ra[1],str,sizeof(str)); //Tien trinh con doc cac xau ket qua vao duong ong//
                if (rc==-1)
                {
                    perror("Loi Ghi Ket Qua");
                    close(pipe_vao[0]);
                    close(pipe_ra[1]);
                    exit(1);
                }
                break;
            }
            else{

                rc = write(pipe_ra[1],str1,sizeof(str1));
                 //Tien trinh con doc cac xau ket qua vao duong ong//
                if (rc==-1)
                {
                    perror("Loi Ghi Ket Qua");
                    close(pipe_vao[0]);
                    close(pipe_ra[1]);
                    exit(1);
                }
            }


        }


        close(pipe_vao[0]);
        close(pipe_ra[1]);
        exit(0);
}
int main()
 {
    int chatoicon[2];
    int contoicha[2];
    int pic=0;
    int rc;
    rc=pipe(chatoicon);
    if(rc==-1)
    {
        perror("Loi tien trinh cha toi con");
        exit(1);
    }

    rc=pipe(contoicha);
    if(rc==-1)
    {
        perror("Loi tien trinh con toi cha");
        exit(1);
    }


    pic=fork();
    if(pic==-1)
        perror("Loi Chuong trinh");
    else
        if(pic==0)
            {
                do_child(contoicha,chatoicon);
            }
        else
            {
                do_parent(chatoicon,contoicha);
            }



    return 0;
}

