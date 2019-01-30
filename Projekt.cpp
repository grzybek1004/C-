#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void funkcja_1(char nazwa[]){
	int i=0,j=0;
	string linia;
	char x;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while(!wejscie.eof()){
		wejscie.get(x);
		if(!isspace(x)) i++; //znaki bez spacji
	}
	wejscie.close();
	wejscie.open(nazwa);
        while(getline(wejscie,linia)){
    cout << linia << endl;
    j += linia.length(); //wszystkie znaki
}


	wejscie.close();
	cout<<"Ilosc znakow ze spacja: "<<j<<" bez spacji: "<<i;

}

void funkcja_2(char nazwa[]){
	string linia;
	int i=0,j=0;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while( getline(wejscie, linia, '\n') ){
        for(i=0; i<linia.length();i++){
            if(isalnum(linia[i])){
                i++;
                while(isalnum(linia[i])){
                    i++;
                }
            j++;
            }
        }
    }

	cout<<"Ilosc slow wynosi: "<<j;
}

void funkcja_3(char nazwa[]){
    string linia;
    int i=0;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while(getline(wejscie,linia)) i++;
	wejscie.close();
	cout<<"Liczba linii wynosi: "<<i;
	return;
}

void funkcja_4(char nazwa[]){
    char x,y;
    int i=0;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while(!wejscie.eof()){
		wejscie.get(x);
		if((x=='.'||x=='?'||x=='!')&&y!='.') i++; //znaki bez spacji
		y=x;
	}
	wejscie.close();
	cout<<"Ilosc zdan wynosi: "<<i;
}

void funkcja_5(char nazwa[]){
  string linia,tmp;
	int l=0,i,j,p,k,a=0;
	char x;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while( getline(wejscie, linia, '\n') ){
        for(i=0; i<linia.length();i++){
            if(isalnum(linia[i])){
                i++;
                while(isalnum(linia[i])){
                    i++;
                }
            l++;
            }
        }
    }
    wejscie.close();
    string * t = new string[l];
  //t=(string*)calloc(l,sizeof(string));
    //t=(string*)malloc(l* sizeof(string));
  wejscie.open(nazwa);
  if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while ( getline(wejscie, linia, '\n') ){
        for(i=0; i<linia.length();i++){
            if(isalnum(linia[i])){
                p=i;
                i++;

                k=1;
                while(isalnum(linia[i])){
                    i++;
                    k++;
                }
            t[a]= linia.substr(p,k);
            a++;
            }
        }
    }
    //for(i=0;i<l;i++) cout<<t[i]<<endl;

     for(i=0;i<l;i++){
        tmp=t[i];
        for(j=0;j<tmp.length();j++){
            if(tmp[j]>=65 && tmp[j]<=90) {
                    tmp[j]+=32;
                }
        }
        t[i]=tmp;
    }
    cout<<l<<endl;
    cout<<"Ilosc wystapien wszystkich slow: "<<endl;
    a=0;

    for(i=0;i<l;i++) cout<<t[i]<<endl;
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(j<i){
                if(t[j]==t[i]) break;
            }
            else if(t[j]==t[i]) a++;

        }
        if(a==0) continue;
        cout<<t[i]<<" = "<<a<<endl;
        a=0;
    }
    delete [] t;
    return;
}

void funkcja_6(char nazwa[], char slowo[]){
  string linia,tmp;
	int l=0,i,j,p,k,a=0;
	char x;
	ifstream wejscie(nazwa);
	if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while( getline(wejscie, linia, '\n') ){
        for(i=0; i<linia.length();i++){
            if(isalnum(linia[i])){
                i++;
                while(isalnum(linia[i])){
                    i++;
                }
            l++;
            }
        }
    }
    wejscie.close();
    string * t = new string[l];
  //t=(string*)calloc(l,sizeof(string));
    //t=(string*)malloc(l* sizeof(string));
  wejscie.open(nazwa);
  if(!wejscie){
		 cout<<"Blad otwarcia pliku";
		return;
	}
	while ( getline(wejscie, linia, '\n') ){
        for(i=0; i<linia.length();i++){
            if(isalnum(linia[i])){
                p=i;
                i++;

                k=1;
                while(isalnum(linia[i])){
                    i++;
                    k++;
                }
            t[a]= linia.substr(p,k);
            a++;
            }
        }
    }
    //for(i=0;i<l;i++) cout<<t[i]<<endl;

     for(i=0;i<l;i++){
        tmp=t[i];
        for(j=0;j<tmp.length();j++){
            if(tmp[j]>=65 && tmp[j]<=90) {
                    tmp[j]+=32;
                }
        }
        t[i]=tmp;
    }
    cout<<l<<endl;
    cout<<"Ilosc wystapien wszystkich slow: "<<endl;
    a=0;

    for(i=0;i<l;i++) cout<<t[i]<<endl;
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(j<i){
                if(t[j]==t[i]) break;
            }
            else if(t[j]==t[i]) a++;

        }
        if(a==0) continue;
        cout<<t[i]<<" = "<<a<<endl;
        a=0;
    }
    delete [] t;
    return;
}

int main(){
	char nazwa[50],slowo;
	int a;
	cout<<"Analiza pliku tekstowego \n";
	cout<<"Podaj nazwe pliku do analizy: ";
	scanf("%s", nazwa);
	cout<<"\n Prosze wybrac opcje analizy: \n";
	cout<<"1. Ilosc znakow \n";
	cout<<"2. Ilosc slow \n";
	cout<<"3. Ilosc linii \n";
	cout<<"4. Ilosc zdan \n";
	cout<<"5. Licznosci wystapien kazdego ze slow uzytych w analizowanym pliku \n";
	cout<<"6. Licznosci zadanego slowa \n";
	cout<<"7. Srednia dlugosc slowa \n";
	cout<<"8. Srednia liczba slow na zdanie \n";
	cin>>a;
	switch(a){
	case 1:
        funkcja_1(nazwa);
        break;

	case 2:
		funkcja_2(nazwa);
		break;

	 case 3:
		funkcja_3(nazwa);
		break;
	 case 4:
		funkcja_4(nazwa);
		break;
	case 5:
		funkcja_5(nazwa);
		break;
	 case 6:
	 	cout<<("Podaj slowo: ");
	 	scanf("%s", slowo);
		funkcja_6(nazwa, slowo);
		break;
	 case 7:
		//funkcja_7(nazwa);
		break;
	 case 8:
		//funkcja_8(nazwa);

		break;
    }
	return 0;
}


