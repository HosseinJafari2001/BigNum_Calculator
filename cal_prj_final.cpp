/*

نام و نام خانوادگی: حسین جعفری

اعضا ی گروه : علیرضا بلوچی  آرشام بهمنش   حسین جعفری
گروه ۳

عملکرد برنامه :
با اجرا  ی برنامه پیغامی مبتنی بر این دستور محاسباتی وارد شود به کاربر نمایش دادع می شود
در صورت اینکه فرمت دستور ورودی رعایت نشود خطا داده می شود و از کاربر دوباره دستور محاسباتی می خواد.

این برنامه حاصل جمع و ضرب و تقسیم و تفریق و باقی مانده دو عدد حدااکثر هر کدام با طول ۱۰۰ عدد را
انجام می دهد.

توجه شود که در محاتسبه ی تقسیم و باقی مانده برای دو عدد که اختلاف طول دوعدد بیشتر از ۷ رقم باشد برنامه کند است.

برای خروج از برنامه و پایان دادن کاربر باید یکی از کلمات زیر را وارد کند.
END
end


*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;

int compaire(int c1,int c2, int arr1[],int arr2[])//تابع مقایسه بزرگی دو عدد وارد شده
{
   if(c1>c2){return 1;}
    if(c2>c1){return 2;}
    if(c1==c2)
    {
        for(int i=0;i<c1;i++)
        {
            if(arr1[i]>arr2[i]){return 1;break;}
            if(arr1[i]<arr2[i]){return 2;break;}
            if(i==c1-1){return 0;}
        }
    }
}
void summation (int c1,int c2,int arr1[],int arr2[])//تابع جمع
{
   int t=c1>=c2 ? c1 : c2,p=t++;//پیدا کردن طول عدد بزرگتر و گذاشتن یکی بیشتر ان به عنوان طول ارایه جواب
   int l=c1-1,o=c2-1,sum[t]={0};//ارایه جواب

   while(o>=0 || l>=0)//عمل تکرار برای جمع دو عدد
   {
       if(l<0){l++;arr1[l]=0;}
       if(o<0){o++;arr2[o]=0;}
       if((arr1[l]+arr2[o]+sum[t-1])>9){sum[t-2]++;}//اگر جمع دو عدد زیر هم بیشتر از 10 باشد باقی مانده در ارایه جواب نوشته شده و یک عدد به عدد بعدب ارایه جواب اضافه میشود
       sum[t-1]=(arr1[l]+arr2[o]+sum[t-1])%10;//باقی مانده جمع دو عدد در ارایه جواب ریخته میشود
       t--;l--;o--;
   }
    int u=0;for(int i=0;i<t;i++){if(sum[i]==0){u++;}}//حذف درایه های برابر صفر قبل جواب
    for(u;u<p+1;u++){cout<<sum[u];}// نمایش درایه به درایه ارایه جواب
}
void submission (int c1,int c2,int arr1[],int arr2[])// تابع تفریق
{
    int q;
    if(c1==c2)//بررسی بزرگی عدد در صورت هم طول بودن انها
    {
        for(int i=0;i<c1;i++)
        {
            if(arr1[i]>arr2[i]){q=1;break;}
           if(arr2[i]>arr1[i]){q=2;break;}
           if(i==c1-1){cout<<"0";}//نمایش عدد صفر در صورت برابری دو عدد
        }
    }
    if(c1>c2 || q==1)//اگر عددد اول بزرگتر باشد
    {
       int t=c1,p=t;//عدد بزرگتر به عنوان طول ارایه جواب
       int l=c1-1,o=c2-1,sum[t]={0};

       while(o>=0 || l>=0)// تکرار برای تفریق دو رقم
       {
           if(l<0){l++;arr1[l]=0;}
           if(o<0){o++;arr2[o]=0;}
           if(arr1[l]>=arr2[o]){sum[t-1]=arr1[l]-arr2[o];}//تفریق دو عدد زیر هم و گزاشتن به عنوان جواب در صورت بزرگ بودن رقم عدد اول
           else{sum[t-1]=arr1[l]+10-arr2[o];arr1[t-2]--;}//تفریق دو عدد زیر هم و گزاشتن به عنوان جواب در صورت بزرگ بودن رقم عدد دوم
           t--;l--;o--;
       }
        int u=0;for(int i=0;i<p;i++){if(sum[i]==0){u++;}else break;}//حذف درایه های برابر صفر قبل جواب
        for(u;u<p;u++){cout<<sum[u];}// نمایش درایه به درایه ارایه جواب
    }

   if(c2>c1 || q==2)//اگر عدد دوم برگتر باشد
    {
       int t=c2,p=t;//عدد بزرگتر به عنوان طول ارایه جواب
       int l=c1-1,o=c2-1,sum[t]={0};
       while(o>=0 || l>=0)// تکرار برای تفریق دو رقم
       {
           if(l<0){l++;arr1[l]=0;}
           if(o<0){o++;arr2[o]=0;}
           if(arr2[o]>=arr1[l]){sum[t-1]=arr2[o]-arr1[l];}//تفریق دو عدد زیر هم و گزاشتن به عنوان جواب در صورت بزرگ بودن رقم عدد اول
           else{sum[t-1]=arr2[o]+10-arr1[l];arr2[t-2]--;}//تفریق دو عدد زیر هم و گزاشتن به عنوان جواب در صورت بزرگ بودن رقم عدد دوم
           t--;l--;o--;
       }
        int u=0;for(int i=0;i<p;i++){if(sum[i]==0){u++;}else break;}//حذف درایه های برابر صفر قبل جواب
        cout<<'-';for(u;u<p;u++){cout<<sum[u];}// نمایش درایه به درایه ارایه جواب
    }

}
void multiplication (int c1,int c2,int arr1[],int arr2[])//تابع ضرب
{
    int q;
   if(c1==c2) {q=1;}
   if(c1>c2 || q==1)//اگر عدد اول بزرگتر باشد
    {
       int t=c1+c2,p=t,f=c2;//جمع تعداد رقم های دو عدد به عنوان اندازه ارایه جواب
       int l=c1-1,o=c2-1,sum[t]={0};
       int arrm[f][t];int i=0;for(int i=0;i<f;i++){for(int j=0;j<t;j++){arrm[i][j]=0;}}// تعرف ارایه ضرب رقم در عدد دیگر
       while(o>=0)
       {
           int d=0,b=p;l=c1-1;
           for(l;l>=0;l--)
           {
             arrm[i][b-i-1]= (arrm[i][b-i-1]+(arr1[l]*arr2[o]))%10;// گذاشتن باقی مانده ضرب دو رقم بر 10 در ارایه ضربها
             d=(arr1[l]*arr2[o]+d)/10;arrm[i][b-i-2]+=d;b--;// تعیین به اصطلاح در دسترس عدد و جمع ان با درایه بعدی
           }
           i++;o--;
       }
      for(int i=p-1;i>=0;i--)// تعیین به اصطلاح در دسترس عدد و جمع ان با درایه بعدی
       {
           int r=0;
           for(int j=f-1;j>=0;j--){r+=arrm[j][i];}
           sum[i]+=r%10;if(i>0){sum[i-1]+=r/10;}
       }
        int u=0;for(int i=0;i<p;i++){if(sum[i]==0){u++;}else break;} if(u==p){cout<<'0';}//حذف صفر های قبل جواب
        for(u;u<p;u++){cout<<sum[u];}// نمایش درایه به درایه ارایه جواب
    }
   if(c2>c1)//اگر عدد دوو بزرگتر باشد
    {
       int t=c1+c2,p=t,f=c1;//جمع تعداد رقم های دو عدد به عنوان اندازه ارایه جواب
       int l=c1-1,o=c2-1,sum[t]={0};
       int arrm[f][t]={0};int i=0;for(int i=0;i<f;i++){for(int j=0;j<t;j++){arrm[i][j]=0;}}// تعرف ارایه ضرب رقم در عدد دیگر

       while(l>=0)
       {
           int d=0,b=p;o=c2-1;
           for(o;o>=0;o--)
           {
             arrm[i][b-i-1]= (arrm[i][b-i-1]+(arr1[l]*arr2[o]))%10;// گذاشتن باقی مانده ضرب دو رقم بر 10 در ارایه ضربها
             d=(arr1[l]*arr2[o]+d)/10;arrm[i][b-i-2]+=d;b--;// تعیین به اصطلاح در دسترس عدد و جمع ان با درایه بعدی
           }
           i++;l--;
       }
       for(int i=p-1;i>=0;i--)// تعیین به اصطلاح در دسترس عدد و جمع ان با درایه بعدی
       {
           int r=0;
           for(int j=f-1;j>=0;j--){r+=arrm[j][i];}
           sum[i]+=r%10;if(i>0){sum[i-1]+=r/10;}
       }
        int u=0;for(int i=0;i<p;i++){if(sum[i]==0){u++;}else break;} if(u==p){cout<<'0';}//حذف صفر های قبل جواب
        for(u;u<p;u++){cout<<sum[u];}// نمایش درایه به درایه ارایه جواب
    }
}
void division (int c1,int c2,int arr1[],int arr2[])// تابع تقسیم
{
    if(c2>c1){cout<<'0';}
    else
   {int arrs1[c1]={0};for(int i=0;i<c1;i++){arrs1[i]=arr1[i];}//انداختن ارایه عدد اول در ارایه دیگر برای عدم تغییر ان در طول محاسبه
    int arrs2[c1]={0};for(int i=c1-1;i>=0;i--){if(i<c1-c2){break;}arrs2[i]=arr2[i-(c1-c2)];}//انداختن عدد دوم در ارایه در برای عدم تغییر در طول محاسبه
    int cd[c1]={0},u[c1]={0};u[c1-1]=1;
    while( compaire(c1,c1,arrs1,arrs2)!=2 )//تا زمانی که عدد اول بزرگتر باشد
    {
        int t=c1;//انازه عدد بزرگتر به عنوان طول ارایه جواب
        int l=c1-1,sum[t]={0};
        int arrs2[c1]={0};for(int i=c1-1;i>=0;i--){if(i<c1-c2){break;}arrs2[i]=arr2[i-(c1-c2)];}//مقدار دهی دوباره عدد دوم به دلیل تغیر در طول محاسبه
        while(l>=0)// تفریق عدد کوچکتر از بزرگتر
          {
           if(arrs1[l]>=arrs2[l]){sum[t-1]=arrs1[l]-arrs2[l];}
           else{sum[t-1]=arrs1[l]+10-arrs2[l];arrs1[t-2]--;}
           t--;l--;
          }
        for(int i=c1-1;i>=0;i--){arrs1[i]=sum[i];}//انداختن باقی مانده تفریق دو عدد در عدد بزرگتر
        t=c1;
        l=c1-1;int sum1[t]={0};
        while(l>=0)//شمارش تعداد تکرار عمل تفریق دو عدد تا زمانی که عدد اوا بزرگتر است
            {
           if((cd[l]+u[l]+sum1[t-1])>9){sum1[t-2]++;}
           sum1[t-1]=(cd[l]+u[l]+sum1[t-1])%10;
           t--;l--;
            }
        for(int i=c1-1;i>=0;i--){cd[i]=sum1[i];}
    }

          int j=0,i=0;for(j;j<c1-1;j++){if(cd[j]==0){i++;}else break;}// حذف صفر های قبل جواب
          for(i;i<c1;i++){cout<<cd[i];}// نمایش جواب
   }
}
void mod (int c1,int c2,int arr1[],int arr2[])// تابع باقی مانده
{
    // تکرار عملیات انجام شده در تابع تقسیم و نمایش اخرین باقی مانده به عنوان جواب
    int q;
    if(c1==c2)
    {
        for(int i=0;i<c1;i++)
        {
            if(arr1[i]>arr2[i]){q=1;break;}
           if(arr2[i]>arr1[i]){q=2;break;}
           if(i==c1-1){cout<<"0";}
        }
    }
 if(c1>c2 || q==1)
    {
        int arrs1[c1]={0};for(int i=0;i<c1;i++){arrs1[i]=arr1[i];}
        int arrs2[c1]={0};for(int i=c1-1;i>=0;i--){if(i<c1-c2){break;}arrs2[i]=arr2[i-(c1-c2)];}
        int cd[c1]={0},u[c1]={0};u[c1-1]=1;int sum[c1]={0};
        while( compaire(c1,c1,arrs1,arrs2)!=2 )
        {
            int t=c1;
            int l=c1-1;sum[t]={0};
            int arrs2[c1]={0};for(int i=c1-1;i>=0;i--){if(i<c1-c2){break;}arrs2[i]=arr2[i-(c1-c2)];}
            while(l>=0)
              {
               if(arrs1[l]>=arrs2[l]){sum[t-1]=arrs1[l]-arrs2[l];}
               else{sum[t-1]=arrs1[l]+10-arrs2[l];arrs1[t-2]--;}
               t--;l--;
              }
            for(int i=c1-1;i>=0;i--){arrs1[i]=sum[i];}
        }

          int j=0,i=0;for(j;j<c1-1;j++){if(cd[j]==0){i++;}else break;}i=0;
          while(sum[i]==0){i++;}
          for(i;i<c1;i++){cout<<sum[i];}

    }
    if(c2>c1 || q==2){for(int i=0;i<c1;i++){cout<<arr1[i];}}
}
main()
{
    cout<<"for exit enter END or end: \n\n";
    while(1)//حلقه تکرار دستورگیری و محاسبه
    {
   cout<<"enter numbers like num1 + num 2:"<<endl; string a;getline(cin,a);if(a=="END" || a=="end"){return 0;}//گرفتن دستور به صورت رشته
   int c1=0, c2=0, i=0, mc1=0, mc2=0; bool p=0;
//------------------------------------------------------------------------------------------------------
   if(a[0]=='-'){mc1=1;i++;}//تعیین علامت عدد اول
   while (a[i]!='+' && a[i]!='-' && a[i]!='/' && a[i]!='*' && a[i]!='%')//صحت سنجی عدد اول
   {

       if (a[i]=='0'){if(a[i-1]!='0' && a[i-1]!='1' && a[i-1]!='2' && a[i-1]!='3' && a[i-1]!='4' && a[i-1]!='5'
           && a[i-1]!='6' && a[i-1]!='7' && a[i-1]!='8' && a[i-1]!='9')
           {if(a[i+1]=='='||a[i+1]=='+'||a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='%'||a[i+1]==' '){}
           else {cout<<"invalid input please  try again:\n";p=1;break;}}}//بررسی عدد که مثلا به شکل 054 نباشد
       if( a[i]=='0' ||a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5'
           || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' ){c1++;i++;}//شمارش اندازه عدد اول
       else if(a[i]==' '){if(a[i+1]=='+' || a[i+1]=='-' || a[i+1]=='*' || a[i+1]=='/' || a[i+1]=='%' || a[i+1]==' '){i++;}
       else {cout<<"invalid input please  try again:\n";p=1;break;}}//بررسی اینکه اسپیس به جز قبل و بعد عملگرها جای دیگری نباشد
       else {cout<<"invalid input please  try again:\n";p=1;break;}
   }i++;if(p){continue;} if(c1==0){cout<<"invalid input please  try again:\n";continue;}//اگر عدد نباشد خطا بگیرد
   while (a[i]!='=' )//صحت سنجی عدد دوم
   {

        if (a[i]=='0'){if(a[i-1]!='0' && a[i-1]!='1' && a[i-1]!='2' && a[i-1]!='3' && a[i-1]!='4' && a[i-1]!='5'
           && a[i-1]!='6' && a[i-1]!='7' && a[i-1]!='8' && a[i-1]!='9')
           {if(a[i+1]=='='||a[i+1]=='+'||a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='%'||a[i+1]==' '){}
           else {cout<<"invalid input please  try again:\n";p=1;break;}}}//بررسی عدد که مثلا به شکل 054 نباشد
        if(a[i]=='0'|| a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5'
           || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9'){c2++;i++;}//شمارش اندازه عدد دوم
        else if(a[i]==' '){if(a[i+1]=='='||a[i-1]=='+'||a[i-1]=='-'||a[i-1]=='*'||a[i-1]=='/'||a[i-1]=='%'||a[i-1]==' '||a[i+1]==' '){i++;}
        else {cout<<"invalid input please  try again:\n";p=1;break;}}//بررسی اینکه اسپیس به جز قبل و بعد عملگرها جای دیگری نباشد
        else if(a[i]=='-' && mc2==0){if( a[i+1]=='0' || a[i+1]=='1' || a[i+1]=='2' || a[i+1]=='3' || a[i+1]=='4' || a[i+1]=='5'
           || a[i+1]=='6' || a[i+1]=='7' || a[i+1]=='8' || a[i+1]=='9')
           {if(a[i-1]=='+' || a[i-1]=='-' || a[i-1]=='*' || a[i-1]=='/' || a[i-1]=='%' || a[i-1]==' '){mc2=1;i++;}
           else {cout<<"invalid input please  try again:\n";p=1; break;}}
           else {cout<<"invalid input please  try again:\n";p=1; break;}}//تعیین علامت عدد دوم
        else {cout<<"invalid input please  try again:\n";p=1; break;}
   } if(p){continue;} if(c2==0){cout<<"invalid input please  try again:\n";continue;}//اگر عدد نباشد خطا بگیرد
   if(a[i+1]!='\0'){cout<<"invalid input please  try again:\n";continue;}
//-------------------------------------------------------------------------------------
   static int arr1[100],arr2[100];int j=0,k=0;if(mc1==1){j++;}
   while (a[j]!='+' && a[j]!='-' && a[j]!='/' && a[j]!='*' && a[j]!='%')//ریختن عدد اول در ارایه
   {
       if(a[j]!=' ' || a[j]!='-'){arr1[k]=int(a[j])-48;k++;}j++;
   }
   j++;while(a[j]==' '){j++;}k=0;if(mc2==1){j++;}
   while (a[j]!='=' )//ریختن عدد دوم در ارایه
   {
       if(a[j]!=' ' || a[j]!='-'){arr2[k]=int(a[j])-48;k++;};j++;
   }
//-----------------------------------------------------------------------------------
int g=0,pl=0,mi=0,mu=0,di=0,mo=0;
while(a[g]!='=')//تعیین عملگر دستور
{
    if(a[g]=='+'){pl++;}
    if(a[g]=='-'){mi++;}
    if(a[g]=='*'){mu++;}
    if(a[g]=='/'){di++;}
    if(a[g]=='%'){mo++;}
    g++;
}
if(pl)//فراخوانی تابع جمع در حالات مختلف علامت اعداد
    {if(mc1==0 && mc2==0){summation(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==0){submission(c2,c1,arr2,arr1);cout<<endl;continue;}
     else if(mc1==0 && mc2==1){submission(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==1){cout<<"-";summation(c1,c2,arr1,arr2);cout<<endl;continue;}
    }
if(mu)// فراخوانی تابع ضرب در حالات مختلف علامت اعداد
    {if(mc1==0 && mc2==0){multiplication(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==0){cout<<"-";multiplication(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==0 && mc2==1){cout<<"-";multiplication(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==1){multiplication(c1,c2,arr1,arr2);cout<<endl;continue;}
    }
if(di)// فراخوانی تابع تقسیم در حالات مختلف علامت اعداد
    {if(mc1==0 && mc2==0){division(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==0){cout<<"-";division(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==0 && mc2==1){cout<<"-";division(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==1){division(c1,c2,arr1,arr2);cout<<endl;continue;}
    }
if(mo)// فراخوانی تابع باقی مانده در حالات مختلف علامت اعداد
      {if(mc1==0 && mc2==0){mod(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==0){cout<<"-";mod(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==0 && mc2==1){mod(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==1){cout<<"-";mod(c1,c2,arr1,arr2);cout<<endl;continue;}
      }
if(mi)// فراخوانی تابع تفریق در حالات مختلف علامت اعداد
    {if(mc1==0 && mc2==0){submission(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==0){cout<<"-";summation(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==0 && mc2==1){summation(c1,c2,arr1,arr2);cout<<endl;continue;}
     else if(mc1==1 && mc2==1){submission(c2,c1,arr2,arr1);cout<<endl;continue;}
    }
    }
getch();

}
//
