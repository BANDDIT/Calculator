#include<bits/stdc++.h>
using namespace std;

char s[255];
double digit=0,bantu=0,ans=0,tens1=1;
bool cek_for_loop=false,mins_depan=false,mins_belakang=false;

/**
Created by Arrick Russell Adinoto
**/

void peraturan(){
	printf("Berikut ini adalah beberapa peraturan untuk kalkulator dasar:\n");
	printf("1)Masukkan angka-angka dan operasi hitung melalui keyboard.\n");
	printf("2)Terdapat spasi atau tidak,tidak akan menjadi masalah karena akan dirapihkan oleh program saat dibaca.\n");
	printf("3)Tekan tombol enter setelah kita memasukkan angka dan operasi perhitungan.\n");
	printf("4)Diperbolehkan untuk memasukkan bilangan desimal.\n");
	printf("  Contoh Input yang Dimaksud: 5x3.2-5/7+11/2.13\n");
	printf("                      Output: 20.45003\n");
	printf("5)Tidak diperbolehkan untuk memasukkan bilangan negatif ke dalam operasi perkalian atau pembagian.\n");
	printf("  Contoh Input yang Tidak Diperbolehkan: a)  15x-5 (SALAH)\n");
	printf("                                         b) -12/-3 (SALAH)\n");
	printf("6)Program tidak dapat menampung angka yang terlalu besar.\n");
	printf("7)Dilarang juga menggunakan tanda kurung yang berfungsi sebagai prioritas di dalam operasi perhitungan.\n");
	printf("8)Untuk cara penggunaan, user cukup mengetik operasi hitungnya sesuai simbol-simbol yang berlaku\n");
	printf("  di bawah ini. Misalnya Anda dapat mengetik \"5x3.2-5/7+11/2.13\" ke program dan lalu menekan enter.\n");
	printf("9)Setelah user melakukan input, maka program dapat mengeluarkan output berupa hasil hitung.\n");
	printf("================================================================================================================\n");
	printf("a)Gunakan tanda + untuk +.\n");
	printf("b)Gunakan tanda - untuk -.\n");
	printf("c)Gunakan tanda / untuk pembagian.\n");
	printf("d)Gunakan tanda x(huruf kecil) untuk perkalian.\n");
	printf("  Contoh Input yang Benar:5x3.2-5/7+11/2.13(setelah itu menekan enter)\n");
	printf("  Output:20.45003\n");
	printf("================================================================================================================\n");
	printf("-Ketik huruf C lalu enter untuk membersihkan history perhitungan.\n");
	printf("-Ketik huruf E lalu enter untuk exit.\n");
	printf("================================================================================================================\n");
	printf("Anda Sudah Bisa Memberikan Input Disini.\n");
	printf("\n");
	printf("Contoh\n");
	printf("Input:\n");
	printf("5x3.2-5/7+11/2.13\n");
	printf("Output:\n");
	printf("=20.45003\n");
	printf("\n");
}


void picture(){
	system("CLS");
	printf("\n");
	printf("			      л л                   \n");
	printf("			      л л ллллл     л          л       л                \n");
	printf("			ллллл ллл л     ллл л лллл л л л ллл ллллл лллл лллл             \n");
	printf("			л л л   л л     л л л л    л л л л л   л   л  л л  л         \n"); 
	printf("			л л л   л л     ллл л л    ллл л ллл   л   л  л ллл             \n");
	printf("			л л л ллл ллллл   л л лллл   л л   л   л   лллл л  л               \n");
	printf("	                \n");
	printf("	                \n");
	printf("================================================================================================================\n");
}

void line(){
	printf("================================================================================================================\n");
}

void check_koma(int awal,int akhir){
	/**
	Di void ini tidak hanya untuk mengecek koma saja
	tetapi juga mengconvert substring ke dalam bentuk angka
	**/
	digit=0;
	tens1=1;
	bool check=false;
	double tens2=1;
	for(int i=akhir;i>=awal;i--){
		if(s[i]!='.')tens2*=10;
		else{
			tens1=tens2;
			check=true;
			break;
		}
	}
	
	double tens=1;
	for(int i=akhir;i>=awal;i--){
		if(s[i]!='.'){
			digit=digit+(s[i]-'0')*tens;
			tens*=10;
		}
	}
	
	if(!check){
		tens1=1;
	}
}

void convert_angka_string(int awal,int akhir){
	//awal=0,akhir=2;
	int index=-1;
	char help[255];
	long long digit_help=digit,tens3=trunc(tens1);
	//printf("%s\n",s);
	//printf("digit_help:%lld\n",digit_help);
	//printf("tens1:%lld\n",tens3);
	
	//printf("digit:%lld\n",digit_help);
	//printf("tens3:%lld\n",tens3);

	
	while(digit_help>0||tens3>0){
		index++;
		
		if(digit_help==0&&tens3>0)help[index]='0';
		else help[index]=((digit_help%10)+'0');
		
		//printf("%c\n",help[index]);
		//if(s[index]=='H')printf("%d\n",digit);
		//if(digit_help>=tens1)help[index]=((digit_help%10)+'0');
		//else help[index]='0';
		tens3/=10;
		digit_help/=10;
		if(tens3==1){
			index++;
			help[index]='.';
		}
		//printf("%c\n",help[index]);

	}
	help[index+1]='\0';
	//printf("s: %s\n",s);
	//printf("help: %s\n",help);
	/**
	MASIH ADA BUG
	Kalau enol-nya lebih banyak gimana
	**/
	reverse(help,help+index+1);
	//printf("hellp:%s\n",help);

	//for(int i=0;help[i]!='\0';i++){
	//	printf("%c\n",help[i]);
	//}

	/**
	index=awal-1;
	printf("%d %d\n",awal,akhir);
	//printf("Testing %s\n",help);
	**/
	awal=awal-1;
	for(int i=0;i<strlen(help);i++){
		awal++;
		s[awal]=help[i];
	}
	//printf("s: %s\n",s);

	
	int leng_s=strlen(s),start=awal+strlen(help);
	for(int i=akhir+1;i<leng_s;i++){
		awal++;
		s[awal]=s[i];
	}
	s[awal+1]='\0';
	//printf("s: %s\n",s);
}

void new_convert_angka_string(int awal, int akhir){
	char pinjem[100];
	int it=-1;
	for(int i=akhir+1;i<strlen(s);i++){
		it++;
		pinjem[it]=s[i];
	}
	it++;
	pinjem[it]='\0';
	
	int index=-1;
	char help[255];
	long long digit_help=digit,tens3=trunc(tens1);
	//double digit_help=digit,tens3=trunc(tens1);

	//printf("%s\n",s);
	//printf("digit_help:%lld\n",digit_help);
	//printf("tens1:%lld\n",tens3);
	
	//printf("digit:%lld\n",digit_help);
	//printf("tens3:%lld\n",tens3);

	
	while(digit_help>0||tens3>0){
		index++;
		
		if(digit_help==0&&tens3>0)help[index]='0';
		else help[index]=((digit_help%10)+'0');
		
		//printf("%c\n",help[index]);
		//if(s[index]=='H')printf("%d\n",digit);
		//if(digit_help>=tens1)help[index]=((digit_help%10)+'0');
		//else help[index]='0';
		tens3/=10;
		digit_help/=10;
		if(tens3==1){
			index++;
			help[index]='.';
		}
		//printf("tens3:%lf\n",tens3);
		//printf("help:%s\n",help);
		//printf("%c\n",help[index]);

	}
	help[index+1]='\0';
	//printf("s: %s\n",s);
	//printf("help: %s\n",help);
	/**
	MASIH ADA BUG
	Kalau enol-nya lebih banyak gimana
	**/
	reverse(help,help+index+1);
	//printf("hellp:%s\n",help);

	//for(int i=0;help[i]!='\0';i++){
	//	printf("%c\n",help[i]);
	//}

	/**
	index=awal-1;
	printf("%d %d\n",awal,akhir);
	//printf("Testing %s\n",help);
	**/
	awal=awal-1;
	for(int i=0;i<strlen(help);i++){
		awal++;
		s[awal]=help[i];
	}
	//printf("1s: %s\n",s);
	
	//printf("pinjem:%s\n",pinjem);
	for(int i=0;pinjem[i]!='\0'&&it!=-1;i++){
		awal++;
		s[awal]=pinjem[i];
		//printf("%d: %c\n",i,s[awal]);
	}
	awal++;
	s[awal]='0';
	//s[awal]='\0';
	//printf("char: %c\n",s[awal]);
	//printf("2s: %s\n",s);

	s[awal]='\0';
	//printf("2s: %s\n",s);
	//printf("char: %c\n",s[awal]);
	//printf("s:%s\n",s);

}

void tambah_kurang(){
	bool tambah=true;
	int awal=0,akhir=0;
	
	if(s[0]=='+'||s[0]=='-')awal=1;
	//printf("strlen: %d\n",strlen(s));
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='-')tambah=false;
		else if(s[i]=='+')tambah=true;
		
		if(((s[i+1]=='+'||s[i+1]=='-')&&s[i+1]!='\0')||s[i+1]=='\0'){
			//printf("%d\n",i);
			akhir=i;
			//printf("%d %d\n",awal,akhir);
			
			//check_koma, sekaligus untuk mengconvert ke dalam double
			check_koma(awal,akhir);
			if(tambah)ans+=(digit/tens1);
			else ans-=(digit/tens1);
			awal=i+2;
		}
	}
}

void kali_bagi(){//SEPERTINYA MASALAHNYA ADA DISINI
	int leng=strlen(s),index=-1,it=0;
	//while(s[it]!='\0'){
	do{
		cek_for_loop=false;
		mins_depan=false,mins_belakang=false;
		int belakang=0,depan;
		for(int i=it;s[i]!='\0';i++){
			if(s[i]=='x'){
				bool check=true;
				cek_for_loop=true;
				//Untuk mencari yang dibelakang tanda
				
				//printf("s: %s\n",s);
				
				double digit1,puluhan1;
				digit=0;
				tens1=1;
				for(int j=i-1;j>=0;j--){
					if(s[j-1]=='x'||s[j-1]=='/'||s[j-1]=='+'||s[j-1]=='-'||j==0){
						if(s[j-1]=='-')mins_depan=true;
						check_koma(j,i-1);
						depan=j;
						break;
					}
				}
				digit1=digit;
				puluhan1=tens1;
				
				//Untuk mencari yang di depan tanda
				double digit2,puluhan2;
				digit=0;
				tens1=1;
				int tambah_mins_belakang=1;
				if(s[i+1]=='-'){
					mins_belakang=true;
					tambah_mins_belakang=2;
				}
				for(int j=i+1;s[j]!='\0';j++){
					if(s[j+1]=='x'||s[j+1]=='/'||s[j+1]=='+'||s[j+1]=='-'||s[j+1]=='\0'){
						check_koma(i+tambah_mins_belakang,j);
						belakang=j;
						break;
					}
				}
				digit2=digit;
				puluhan2=tens1;
		
				//Hitung
				digit=digit1*digit2;
				tens1=puluhan1*puluhan2;
				
				//printf("digit1: %lf\n",digit1);
				//printf("digit2: %lf\n",digit2);
				//printf("digit: %lf\n",digit);
				
				////Convert ke string
				//printf("%d %d\n",it,belakang);
				convert_angka_string(depan,belakang);
				
				break;
			}
			else if(s[i]=='/'){
				bool check=true;
				cek_for_loop=true;
				//Untuk mencari yang dibelakang tanda
				double digit1,puluhan1;
				digit=0;
				tens1=1;
				for(int j=i-1;j>=0;j--){
					if(s[j-1]=='x'||s[j-1]=='/'||s[j-1]=='+'||s[j-1]=='-'||j==0){
						if(s[j-1]=='-')mins_depan=true;
						check_koma(j,i-1);
						depan=j;
						break;
					}
				}
				digit1=digit;
				puluhan1=tens1;
				
				//Untuk mencari yang di depan tanda
				double digit2,puluhan2;
				digit=0;
				tens1=1;
				int tambah_mins_belakang=1;
				if(s[i+1]=='-'){
					mins_belakang=true;
					tambah_mins_belakang=2;
				}
				for(int j=i+1;s[j]!='\0';j++){
					if(s[j+1]=='x'||s[j+1]=='/'||s[j+1]=='+'||s[j+1]=='-'||s[j+1]=='\0'){
						check_koma(i+tambah_mins_belakang,j);
						belakang=j;
						break;
					}
				}
				digit2=digit;
				puluhan2=tens1;
		
				//printf("digit1:%lf\n",digit1);
				//printf("digit2:%lf\n",digit2);
				//printf("puluhan1:%lf\n",puluhan1);
				//printf("puluhan2:%lf\n",puluhan2);

				//Hitung
				digit=digit1/digit2;
				tens1=puluhan1/puluhan2;
				
			//	printf("digit: %lf\n",digit);
				
				//CONVERT
				
				int it_bagi=1;
				//printf("digit: %lf\n",digit);
				//printf("tens_1:%lf\n",tens1);
			//	printf("trunc(digit):%lf\n",trunc(digit));
				while(it_bagi<=8&&digit!=trunc(digit)){
					digit*=10;
					tens1*=10;
					it_bagi++;
				}
				//printf("digit_1:%lf\n",digit);
				//printf("tens_1:%lf\n",tens1);
				if(digit*10-trunc(digit)*10>=5)digit=digit+1;
				
				//Convert ke string
				new_convert_angka_string(depan,belakang);
				break;
			}
		}	
		/**
		for(int j=it;s[j]!='\0';j++){
			if(!(s[j]>='0'&&s[j]<='9')){
				belakang=j+1;
				break;
			}
		}
		**/
		//printf("s:%s\n",s);
		//it+=max(it+1,belakang);
	}while(cek_for_loop);
}

//-11.33342737/18933


void kalku_dasar(){	

	//MASUKKANK GAMBAR KALKULATOR BNCC sebagai void biar aman
	bool setting=false;
	picture();
	peraturan();
	while(1){
		//char pos[255];
		//double ans=0;//cek lg yg ini
		ans=0;
		s[0]='\0';
		//s.clear();
		//getchar();
		if(setting){
			printf("Input:\n");
			scanf("%[^\n]",&s);
			getchar();
			fflush(stdin);
		}

		
		
		//printf("%s\n",s);
		bool check_a=false;
		
		/**
		for(int i=0;s[i]!='\0';i++){
			if(s[i]!=' '){
				index++;
				pos[index]=s[i];
			}
			if(s[i]=='a'||s[i]=='A')check_a=true;
			//printf("0\n");
		}
		//if(!check_a)ans=0;
		strcpy(s,pos);
		**/
		int leng=strlen(s),index=-1;
		for(int i=0;i<leng;i++){
			if(s[i]!=' '){
				index++;
				s[index]=s[i];
			}
		}
		
		if(s[0]=='e'||s[0]=='E'){
			return;
		}
		else if(s[0]=='c'||s[0]=='C'){
			picture();
			peraturan();
		}
		else{
			//printf("%s\n",s);
			//tambah_kurang();
			//check_koma(0,strlen(s)-1);
			//ans+=digit;
			//printf("%.5lf\n",ans);
			//printf("%lf\n",digit);
			//bantu=0;
			kali_bagi();
			//printf("Jadi: %s\n",s);
			tambah_kurang();
			//ans=ans+bantu;
			if(setting){
				printf("Output:\n");
				printf("=%.5lf\n",ans);
			}
			printf("\n");
			setting=true;
			/**
			printf("s[10]:%c\n",s[10]);
			printf("strlen2: %d\n",strlen(s));
			for(int i=0;i<strlen(s);i++)printf("%c\n",s[i]);
			printf("\n");
			**/
		}

	}

}

void kalku_sains(){
	int input;
	ans=0;
	do{
		char user_input[100],simbol[100],tambahan[100];
		double angka2;
		system("CLS");
		picture();
		printf("Nilai Ans:%lf\n",ans);
		printf("Apakah Anda akan memasukkan nilai Ans ke perhitungan Anda?\n");
		printf("1)Ya\n");
		printf("2)Tidak\n");
		printf("Pilihan Anda:");
		scanf("%s",&user_input);
		//getchar();
		printf("===========================================================================\n");
		//printf("%s\n",user_input);
		if(user_input[0]=='2'){
			ans=0;
			printf("Apakah Anda Menginginkan Simbol Berikut Pada Bilangan Anda?\n");
			printf("1)Tidak Dibutuhkan\n");
			printf("2)Sin\n");
			printf("3)Cos\n");
			printf("4)Tan\n");
			printf("5)Sqrt(akar)\n");
			printf("6)X^2(X pangkat 2)\n");
			printf("7)Pangkat(Format: a pangkat b)\n");
			printf("8)Log(Format: a log b)\n");
			printf("Pilihan Anda:");
			scanf("%s",&tambahan);
			//getchar();
			printf("===========================================================================\n");
			if(tambahan[0]=='7'||tambahan[0]=='8'){
				double a,b;
				printf("Masukkan Angka a:");
				scanf("%lf",&a);
				printf("===========================================================================\n");
				printf("Masukkan Angka b:");
				scanf("%lf",&b);
				if(tambahan[0]=='7')ans=pow(a,b);
				else if(tambahan[0]=='8')ans=(log(b)/log(a));
			}
			else{
				printf("Masukkan Angka:");
				scanf("%lf",&ans);
				if(tambahan[0]=='2')ans=sin(ans);
				else if(tambahan[0]=='3')ans=cos(ans);
				else if(tambahan[0]=='4')ans=tan(ans);
				else if(tambahan[0]=='5')ans=sqrt(ans);
				else if(tambahan[0]=='6')ans=ans*ans;
			}

			//getchar();
			printf("===========================================================================\n");

		}

		printf("Pilih Simbol Untuk Operasi Perhitungan Anda:\n");
		printf("1)+\n");
		printf("2)-\n");
		printf("3)x\n");
		printf("4):(bagi)\n");
		printf("Pilihan Anda:");
		scanf("%s",&simbol);
		//getchar();
		printf("===========================================================================\n");
		printf("Apakah Anda Menginginkan Simbol Berikut Pada Bilangan Anda?\n");
		printf("1)Tidak Dibutuhkan\n");
		printf("2)Sin\n");
		printf("3)Cos\n");
		printf("4)Tan\n");
		printf("5)Sqrt(akar)\n");
		printf("6)X^2(X pangkat 2)\n");
		printf("7)Pangkat(Format: a pangkat b)\n");
		printf("8)Log(Format: a log b)\n");
		printf("Pilihan Anda:");
		scanf("%s",&tambahan);
		//getchar();
		printf("===========================================================================\n");
		if(tambahan[0]=='7'||tambahan[0]=='8'){
			double a,b;
			printf("Masukkan Angka a:");
			scanf("%lf",&a);
			printf("===========================================================================\n");
			printf("Masukkan Angka b:");
			scanf("%lf",&b);
			printf("===========================================================================\n");
			if(tambahan[0]=='7')angka2=pow(a,b);
			else if(tambahan[0]=='8')angka2=(log(b)/log(a));
		}
		else{
			printf("Masukkan Angka:");
			scanf("%lf",&angka2);
			if(tambahan[0]=='2')angka2=sin(angka2);
			else if(tambahan[0]=='3')angka2=cos(angka2);
			else if(tambahan[0]=='4')angka2=tan(angka2);
			else if(tambahan[0]=='5')angka2=sqrt(angka2);
			else if(tambahan[0]=='6')angka2=angka2*angka2;
			//printf("angka2:%lf\n",angka2);
			printf("===========================================================================\n");
		}
		
		if(simbol[0]=='1')ans=ans+angka2;
		else if(simbol[0]=='2')ans=ans-angka2;
		else if(simbol[0]=='3')ans=ans*angka2;
		else ans=ans/angka2;
		printf("Hasil Perhitungan:\n");
		printf("%.5lf\n",ans);
		printf("===========================================================================\n");
		printf("Apakah Anda Masih Ingin Melanjutkan Perhitungan?\n");
		printf("1)Ya\n");
		printf("2)Tidak\n");
		printf("Pilihan Anda:");
		scanf("%d",&input);
		//getchar();
	
	}while(input==1);
}

void about_apps(){
	char input[200];
	//int input;
	//scanf("%d",&input);

	//system("CLS");
	picture();
	printf("I.GENERAL\n");
	printf("	Aplikasi ini adalah aplikasi kalkulator yang diharapkan bisa membantu para user untuk melakukan kalkulasi\n");
	printf("perhitungan dengan cara yang lebih cepat tanpa harus menghitung manual.\n");
	//printf("\n");
	printf("	Di dalam aplikasi ini tersedia 2 fitur kalkulator. Pertama, aplikasi ini menyediakan kalkulator dasar untuk \n");
	printf("melakukan perhitungan dasar yang panjang dalam  waktu yang lebih cepat dan pastinnya dengan  format input  yang \n");
	printf("lebih sederhana. Kedua, aplikasi ini juga menyediakan fitur kalkulator saintifik yang berfungsi untuk melakukan \n");
	printf("kalkulasi  menggunakan  prinsip matematika  yang lebih lanjut seperti sin,cos,tan, dll. Selain fitur kalkulator,\n");
	printf("terdapat juga  menyediakan menu help yang nantinnya juga menjelaskan tentang cara menggunakan aplikasi ini agar \n");
	printf("lebih mudah dipahami oleh user. \n");
	//printf("\n");
	printf("	Dengan  adanya fitur-fitur  yang sudah disajikan, selaku pembuat sangat berharap agar  aplikasi  ini  dapat\n");
	printf("bermanfaat bagi para user.\n");
	printf("\n");
	
	printf("II.Kalkulator Dasar\n");
	printf("	Kalkulator  Dasar yang  dimaksud di dalam aplikasi ini  adalah kalkulator yang melakukan  operasi aritmatika\n  ");
	printf("seperti tambah, kurang,  kali dan bagi. Meskipun  demikian, kalkulator ini dapat  menjalankan operasi aritmatika\n");
	printf("tanpa harus mengisi banyak pertanyaan.\n");
	printf("Kelebihan:\n");
	printf("-Dapat melakukan operasi dengan bilangan yang banyak secara sekaligus, misal:5x6+3-2. \n");
	printf("Kekurangan:\n");
	printf("-Prinsip matematika yang digunakan di dalam aplikasi ini masih sangat terbatas. Tidak ada sin,cos,tan,log,dll.\n");
	printf("-Tidak dapat memasukkan bilangan negatif pada operasi perkalian atau pembagian.\n");
	printf(" contoh: -15x-15\n");
	
	printf("\n");
	
	printf("III.Kalkulator Saintifik\n");
	printf("	Kalkulator  saintifik  di dalam  aplikasi ini  adalah  kalkulator  yang  mampu untuk  mengkalkulasi  operasi\n");
	printf("matematika tingkat lanjut seperti sin,cos,tan,logaritma,  dan sebagainya. Meskipun demikian kalkulator ini tidak\n");
	printf("dapat menampung angka dan operasi yang banyak dalam sekaligus.\n");
	printf("Kelebihan:\n");
	printf("-Dapat melakukan operasi matematika tingkat lanjut.\n");
	printf("Kelemahan:\n");
	printf("-Tidak dapat melakukan operasi matematika yang banyak dalam sekali input.\n");
	printf("=================================================================================================================\n");
	printf("Tekan Enter Jika Ingin Kembali Ke Halaman Utama.\n");
	getchar();
	scanf("%[^\n]",&input);
	getchar();
	//scanf("%[^\n]",&input);

	//getchar();
}

void help(){
	char input[100];
	picture();
	printf("I.GENERAL\n");
	printf("	Pada bagian halaman ini akan dijelaskan mengenai cara menggunakan aplikasi ini.Di dalam aplikasi ini, untuk \n");
	printf("berpindah halaman sesuai yang dituju dengan menuliskan nomor opsi yang berisikan halaman tersebut.\n");
	printf("Contoh: \n");
	printf("1.Kalkulator Dasar\n");
	printf("2.Kalkulator Saintifik\n");
	printf("3.About Apps\n");
	printf("4.Help\n");
	printf("5.Exit\n");
	printf("Pilihan Anda:\n");
	printf("	Pada opsi yang seperti ini, Anda  cukup menuliskan angka lalu menekan tombol enter setelah  menulis  angka.\n");
	printf("Misalnya jika Anda ingin exit, maka yang perlu Anda lakukan adalah cukup menekan angka 5, lalu setelah itu klik\n");
	printf("enter. Dengan demikian, maka anda sudah exit dari aplikasi.\n");
	printf("\n");
	printf("II.Kalkulator Dasar\n");
	printf("	Cara penggunaan kalkulator dasar sebenarnya cukup sederhana. Namun ada beberapa hal yang harus dipahami oleh\n");
	printf("User.\n");
	printf("	Hal-hal tersebut adalah sebagai berikut:\n");
	printf("	1)Hanya boleh menggunakan tambah kurang kali dan bagi di dalam perhitungan, tidak boleh ada simbol lain.\n");
	printf("	2)Tidak diperbolehkan menggunakan Ans.\n");
	printf("	3)Penggunaan spasi diperbolehkan karena akan dirapihkan sendiri oleh program ketika diinput.\n");
	printf("	4)Jika format input menyalahi aturan, maka program akan bisa langsung dinyatakan error.\n");
	printf("Contoh Penulisan yang Benar:\n");
	printf("1+2x5+3\n");
	printf("5/3+ 6+ 1000 000\n");
	printf("Contoh Penulisan yang Salah:\n");
	printf("15xsin(60)\n");
	
	printf("\n");
	printf("III.Kalkulator Saintifik\n");
	printf("	Cara menggunakan kalkulator ini sudah lebih terpadu jika dibandingkan kalkulator dasar.User cukup memasukkan\n");
	printf("input sesuai permintaan ataupun opsi yang sudah disediakan.\n");
	printf("	Jika user memasukkan input yang berada diluar opsi yang sudah disediakan, maka program secara otomatis akan\n");
	printf("memilih salah satu opsi dengan sendirinnya ataupun output langsung dinyatakan error ataupun invalid.\n");
	
	printf("=================================================================================================================\n");
	printf("Tekan Enter Jika Ingin Kembali Ke Halaman Utama.\n");
	getchar();
	scanf("%[^\n]",&input);
	getchar();
}



int main(){
	do{
		char input[100];
		//system("CLS");
		picture();
		printf("1.Kalkulator Dasar\n");
		printf("2.Kalkulator Saintifik\n");
		printf("3.About Apps\n");
		printf("4.Help\n");
		printf("5.Exit\n");
		printf("Pilihan Anda:");
		scanf("%s",&input);
		if(input[0]=='1')getchar(),kalku_dasar();
		else if(input[0]=='2')kalku_sains();
		else if(input[0]=='3'){
			about_apps();
		}
		else if(input[0]=='4')help();
		else{
			system("CLS");
			break;
		} 
		
		
	}while(1);
}
