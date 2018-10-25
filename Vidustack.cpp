#include<stdio.h>
#include <unistd.h>     //Khai bao su dung Pipe va mot so ham cua Linux//
#include <stdlib.h>     //Cac ham chuan cua Linux//
#include <sys/types.h>
#include <math.h>       //Thu vien toan hoc//
#include <string.h>     //Khai bao su dung chuoi//
#include <stack>
using namespace std;

stack <char> stack1, stack2, stack3;

// chuyen mang ki tu co do dai la i thanh so nguyen tuong ung voi no

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

void printStack1(){
    char fkitu;
    stack <char> fstack;
    while( !stack1.empty() ){
        fkitu = stack1.top();
        stack1.pop();
        fstack.push(fkitu);
        putchar(fkitu);
    }

    while(!fstack.empty()){
        fkitu = fstack.top();
        fstack.pop();
        stack1.push(fkitu);
    }
}

void printStack2(){
    char fkitu;
    stack <char> fstack;
    while( !stack2.empty() ){
        fkitu = stack2.top();
        stack2.pop();
        fstack.push(fkitu);
        putchar(fkitu);
    }

    while(!fstack.empty()){
        fkitu = fstack.top();
        fstack.pop();
        stack2.push(fkitu);
    }
}

void printStack3(){
    char fkitu;
    stack <char> fstack;
    while( !stack3.empty() ){
        fkitu = stack3.top();
        stack3.pop();
        fstack.push(fkitu);
        putchar(fkitu);
    }

    while(!fstack.empty()){
        fkitu = fstack.top();
        fstack.pop();
        stack3.push(fkitu);
    }
}

void lamRongStack3(){
    while( !stack3.empty() ){
        stack3.pop();
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

void tachIntRoiPushVoStack(int fkq /*, stack <char> fstack2*/ ){
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


int tinhBieuThucTrongStackDonGian(stack <char> fstack2) {
    int fa[30], fm[3];
    int fdem1=0, fdem2=0;
    int fk=0,fi=0, fkq=0;
    char fgan='n', fchCon, fchOld=' ';
     //duyet het cac phan tu troong stack2, roi tinh toan theo thuat toan ban dau(k validate)
    while( !fstack2.empty() ) {
        //lay ki tu do ra luu vo bien chCon, pop no ra luon khoi stack2
        fchCon = fstack2.top();
        //pop no ra luon khoi stack2
        fstack2.pop();
        //tang bien dem ki tu len 1
        fdem2 = fdem2+1;

        if((fchCon=='0')||(fchCon=='1')||(fchCon=='2')||(fchCon=='3') ||(fchCon=='4') ||(fchCon=='5') ||(fchCon=='6') ||(fchCon=='7') ||(fchCon=='8')||(fchCon=='9') ) //khog phai ki tu +, -, *, /
        {
             //chuyen ki tu do ve double,sau do -48, sau do chuyen ve kieu char, luu vao str
                   //strcpy(str," ");
            fa[fi] = int (fchCon);
            fa[fi] = (fa[fi] - 48);
            //printf("a[%d] la : %d", fi, fa[fi]);
                   //gcvt(a[i],4,str);      //chuyen double thanh char
            fi++;                           //tang len de luu ki tu, cho lan duyet ki tu tiep theo(beacause while)
            //fn=fi;
        }
        else if((fchCon=='+')||(fchCon=='-'))  //Xu li khi gap ki tu thuc hien phep tinh: +-/*
        {
            fdem1 = fdem1 + 1;
            if(fdem1==1){
                //strcpy(str," ");
                fgan = fchCon;
                //printf("toantu la:");putchar(fgan);
                //strcpy(str,&gan);
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
                        //fkq=fm[fk-1]+fm[fk];

                        //fm[fk-1] = fkq;
                        //fm[fk] = 0;
                        if(fchOld=='-'){

                        }else{

                        }
                        break;
                    }
                    case '-':
                    {
                        //strcpy(str,"=");
                        //fkq=fm[fk-1]-fm[fk]

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

/*
       PHAN LAY KET QUA CUA WHILE STACK2,
    */
    //ki++;
    fkq=0;
    //strcpy(str,"=");
    //strcpy(str1," ");
    fm[fk]=xuly(fi, fa);
    printf("fm cuoi cung: fm[%d] la %d va fm[%d] la %d", fk, fm[fk], fk-1, fm[fk-1]);
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
            printf("Toan tu cuoi la dau -;");
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

/* Ham tinh gia tri bieu thu cphuc tap, chua trong stack KHONG VALIDATE, tuc la Chuoi CHUAN ROI */
int tinhBieuThucTrongStackPhucTap(){

    char fch, fchOld, fchCon;
    int kq;
    while ( !stack1.empty() ) // KHi stack chua rong //
    {
         fch = stack1.top();
         stack1.pop();
         putchar(fch);
         printf("\n");
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

                        printf("In stack2:"); printStack2();printf("\n");

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

                                printf("In stack3:"); printStack3();printf("\n");
                                printf("In stack3:"); printStack3();printf("\n");

                                kq = tinhBieuThucTrongStackDonGian(stack3);
                                printf("Ket qua tinh gt trong stack3 la %d", kq);
                                lamRongStack3();

                                /*  chuyen int kq, thanh cac ki tu thanh phan roi day vo stack1
                                */
                                tachIntRoiPushVoStack(kq);

                                break;

                            }
                            else{

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
        printf("stack2 final:"); printStack2(); printf("\n");
        OppositeStack2();
        printf("stack2 final sau nghich:"); printStack2(); printf("\n");
        kq = tinhBieuThucTrongStackDonGian(stack2);
        return kq;
}

int main(){
   /*
   stack1.push(')');
   stack1.push('2');
   stack1.push('1');
   stack1.push('-');
   stack1.push('2');
   stack1.push('1');
   stack1.push('-');

   stack1.push('2');
   stack1.push('1');
   stack1.push('-');
   stack1.push('-');
   stack1.push('(');
    stack1.push('+');
   */
   stack1.push(')');
   stack1.push(')');
   stack1.push('2');
   stack1.push('-');
   stack1.push('(');
   stack1.push('+');
   stack1.push('1');
   stack1.push('(');


   /*
   int kq = tinhBieuThucTrongStackDonGian(stack1);
   printf("ket qua la :%d", kq);

   */
   /*
   int n = 12345;
   tachIntRoiPushVoStack(n);
   printf("IN lai stack");

   printStack();
   */
   int kq = tinhBieuThucTrongStackPhucTap();

   printf("ket qua la: %d", kq);




   return 0;
}
