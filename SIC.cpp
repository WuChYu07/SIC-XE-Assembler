#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<queue> 
#include<cctype>
#include<algorithm>
#include<math.h>
#include <sstream>
#include <bitset>
#include<cstdio>
#include<cstdlib>
using namespace std ;

vector<string> Table1, Table2, Table3, Table4 ;

typedef struct SA{ //symbol and address
	string symbol ;
	int address ;
} sa; 

vector<sa> Table5, Table6, Table7 ;

typedef struct Content{
	int loc ;
	string str ;
	string opcode ;
} content;
vector<content> record ; //�����C�@��{���X����T 

typedef struct Instruction{
	string mnemonic ;
	vector<int> format ;
	string opcode ;
} ins;

vector<ins> Instable ;

class BuildInstable{
	
	public:
		void Rule(){
			ins s ;
			
			s.mnemonic = "add" ;
			s.format.push_back(3) ;
			s.opcode = "18" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "addf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "58" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "addr" ;
			s.format.push_back(2) ;
			s.opcode = "90" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "and" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "40" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "clear" ;
			s.format.push_back(2) ;
			s.opcode = "B4" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "comp" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "28" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "compf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "88" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "compr" ;
			s.format.push_back(2) ;
			s.opcode = "A0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "div" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "24" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "divf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "64" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "divr" ;
			s.format.push_back(2) ;
			s.opcode = "9C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "fix" ;
			s.format.push_back(1) ;
			s.opcode = "C4" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "float" ;
			s.format.push_back(1) ;
			s.opcode = "C0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "hio" ;
			s.format.push_back(1) ;
			s.opcode = "F4" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "j" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "3C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "jeq" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "30" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "jgt" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "34" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "jlt" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "38" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "jsub" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "48" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "lda" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "00" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldb" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "68" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldch" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "50" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "70" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldl" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "08" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "lds" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "6C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldt" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "74" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ldx" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "04" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "lps" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "D0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "mul" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "20" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "mulf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "60" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "mulr" ;
			s.format.push_back(2) ;
			s.opcode = "98" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "norm" ;
			s.format.push_back(1) ;
			s.opcode = "C8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "or" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "44" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "rd" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "D8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "rmo" ;
			s.format.push_back(2) ;
			s.opcode = "AC" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "rsub" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "4C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "shiftl" ;
			s.format.push_back(2) ;
			s.opcode = "A4" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "shifter" ;
			s.format.push_back(2) ;
			s.opcode = "A8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "sio" ;
			s.format.push_back(1) ;
			s.opcode = "F0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "ssk" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "EC" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "sta" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "0C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stb" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "78" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stch" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "54" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "80" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "sti" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "D4" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stl" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "14" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "sts" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "7C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stsw" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "E8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stt" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "84" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "stx" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "10" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "sub" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "1C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "subf" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "5C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "subr" ;
			s.format.push_back(2) ;
			s.opcode = "94" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "svc" ;
			s.format.push_back(2) ;
			s.opcode = "B0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "td" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "E0" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "tio" ;
			s.format.push_back(1) ;
			s.opcode = "F8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "tix" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "2C" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "tixr" ;
			s.format.push_back(2) ;
			s.opcode = "B8" ;
			Instable.push_back(s) ;
			clean(s) ;
			
			s.mnemonic = "wd" ;
			s.format.push_back(3) ;
			s.format.push_back(4) ;
			s.opcode = "DC" ;
			Instable.push_back(s) ;
			clean(s) ;
		}
		
		void clean( ins &s ){
			s.mnemonic = "" ;
			vector<int>().swap(s.format) ;
			s.opcode = "" ;
		}
};

class BuildTables{
	
	public:
		bool BuildTable1(){
			string filename = "Table1.table" ;
			fstream infile ;
			infile.open( filename.c_str(), ios::in | ios::binary ) ;
			
			if( !infile.is_open() ){
				cout << "### " << filename << " does not exist! ### " << endl << endl ;
				return false ;
			} // if
			
			
			string str, temp = " " ;
			Table1.push_back(temp) ;
			while( getline( infile, str) ){
				temp = "" ;
				for( int i = 0 ; i < str.length() ; i++ ){
					if( str[i] == '\r' || str[i] == ' ' ) Table1.push_back(temp) ;
					else temp = temp + str[i] ;
					
				} // for
				
				
			} // while
			
			if( temp != "" ) Table1.push_back(temp) ;
			infile.close() ;
		} //BuildTable1()
		
		bool BuildTable2(){
			string filename = "Table2.table" ;
			fstream infile ;
			infile.open( filename.c_str(), ios::in | ios::binary ) ;
			
			if( !infile.is_open() ){
				cout << "### " << filename << " does not exist! ### " << endl << endl ;
				return false ;
			} // if
			
			
			string str, temp = " " ;
			Table2.push_back(temp) ;
			while( getline( infile, str) ){
				temp = "" ;
				for( int i = 0 ; i < str.length() ; i++ ){
					if( str[i] == '\r' || str[i] == ' ' ) Table2.push_back(temp) ;
					else temp = temp + str[i] ;
					
				} // for
				
				
			} // while
			
			if( temp != "" ) Table2.push_back(temp) ;
			infile.close() ;
		} // BuildTable2()
		
		bool BuildTable3(){
			string filename = "Table3.table" ;
			fstream infile ;
			infile.open( filename.c_str(), ios::in | ios::binary ) ;
			
			if( !infile.is_open() ){
				cout << "### " << filename << " does not exist! ### " << endl << endl ;
				return false ;
			} // if
			
			
			string str, temp = "" ;
			while( getline( infile, str) ){
				temp = "" ;
				for( int i = 0 ; i < str.length() ; i++ ){
					if( str[i] == '\r' || str[i] == ' ' ){
						if( temp != "" ) Table3.push_back(temp) ;
						
						temp = "" ;
					} // if
					else temp = temp + str[i] ;
					
				} // for
					
			} // while
			
			if( temp != "" ) Table3.push_back(temp) ;
			infile.close() ;
		} //BuildTable3()
		
		bool BuildTable4(){
			string filename = "Table4.table" ;
			fstream infile ;
			infile.open( filename.c_str(), ios::in | ios::binary ) ;
			
			if( !infile.is_open() ){
				cout << "### " << filename << " does not exist! ### " << endl << endl ;
				return false ;
			} // if
			
			
			string str, temp = " " ;
			Table4.push_back(temp) ;
			while( getline( infile, str) ){
				temp = "" ;
				for( int i = 0 ; i < str.length() ; i++ ){
					if( str[i] == '\r' || str[i] == ' ' ) Table4.push_back(temp) ;
					else temp = temp + str[i] ;
					
				} // for
				
				
			} // while
			
			if( temp != "" ) Table4.push_back(temp) ;
			infile.close() ;
		} //BuildTable4()
		
		void BuildotherTable(){
			Table5.resize(100) ; //symbol
			Table6.resize(100) ; //integer
			Table7.resize(100) ; //literal
			for( int i = 0 ; i < 100 ; i++ ){
				Table5[i].address = -1 ;
				Table6[i].address = -1 ;
				Table7[i].address = -1 ;
			} // for
			
		} // BuildAnotherTable
		void BuildTable(){
			BuildTable1() ;
			BuildTable2() ;
			BuildTable3() ;
			BuildTable4() ;
			BuildotherTable() ;
			
		} // BuildTable()
}; 

class Run{
		vector<string> workspace ;
		bool start ;
		int location, line, pass, time, pc ;
		string bs ;
		content c ;
		bool isInstruction, isLiteral, isSymbol, m, isPseudo ;
		string input ;
	public:
		void Set(){
			pass = 1 ;
			location = 0 ; //LOCCTR
			line = 0 ;
			start = false ;
			time = 0 ;
			input = "" ;
		} // Set
		
		bool SetFormat(){
			isInstruction = false, isLiteral  = false, isSymbol  = false, m = false, isPseudo = false ;
		} //SetFormat()
		
		void Begin(){
			cout << "Input Your File Name!" << endl;
			cin >> input ;
		}
		bool Gettoken(){
			string filename = input + ".txt" ;
			fstream infile ;
			infile.open( filename.c_str(), ios::in | ios::binary ) ;
			
			if( !infile.is_open() ){
				cout << "### " << filename << " does not exist! ### " << endl << endl ;
				return false ;
			} // if
			
			string str ;
			time = 0 ;
			while( getline( infile, str) ){
				string temp ;
				bool quot = false ;
				if( str[0] == '\t' ) str = str.substr( 1, str.length() -1 ) ;
				
				
				while( !workspace.empty() ){ //�M��queue 
					vector<string> empty ;
					swap( empty, workspace ) ;
				} // while
				
				temp = "" ;
				for( int i = 0 ; i < str.length() ; i++ ){	
					if( str[i] == '\r' || str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\a' ){
						if( temp == "" ) ; //�p�G�O�Ū��N���n��X 
						else{ //���m  
							//cout << temp << endl;
							workspace.push_back(temp) ;	
							quot = false ; 
									 
						} // else
								
						temp = "" ;
					} // if
					else if( Delimeter( str[i] ) ) {//�Odelimiter 
						if( str[i] == '\'' && quot == false ) {
							//temp = "" ;
							temp = temp + str[i] ;
							quot = true ;
						} // if
						else if( str[i] == '\'' ){
							temp = temp + str[i] ;
							workspace.push_back(temp) ;
							temp = "" ;
						} // else if
						else if( str[i] == '.' ) {
							temp = temp + str[i] ;
							workspace.push_back(temp) ;
							temp = "" ;
						} // else if
						else if( str[i] == '+' || str[i] == '#' || str[i] == '@' || str[i] == '=' ) 
							temp = temp + str[i] ;
						else if( temp != "" ){
							workspace.push_back(temp) ;
							temp = "" ;
						} // else if 
							
					} // else if
					else temp = temp + str[i] ;
							
				} // for
				
				if( temp != "" ) workspace.push_back(temp) ;
				
				if( str[str.length()-1] == '\r' || str[str.length()-1] == '\n' ) str.erase(str.end()-1) ;
				SetFormat() ;
				/*
				for( int i = 0 ; i < workspace.size() ; i++ ){
					cout << workspace[i] << " " ;
				} // for	
				cout << endl;
				*/
				
				if( str[0] - 48 == -48 ) ;
				else if( pass == 1 ){
					c.str = str ;
					Pass1() ;
					time++ ;
				} // else if
				else{
					if( CheckSyntax() ) Pass2() ;
					else if( workspace[0][0] == '.' ) ;
					else record[time].opcode = "Erroe Syntax!" ;
					time++ ;
				} // else
					
				
			} // while
				
			pass++ ;
			
			infile.close() ;
		} // Gettoken()
		
		void Pass1(){
			//�w��Ĥ@��token�A���ˬd�O���O���O�A�O�N�h��榡�A���O�N�Olabel��itable�� 
			//�n�B�zliteral���D
			c.loc = location ;				
					
			for( int i = 0 ; i < workspace.size() ; i++ ){
				if( start == false ){ //�٨S�}�l�L�A�n��M"start"
					if( workspace[i] == "START" ) {
						start = true ;
						
						//��a�}�A16�ন10�i��A�B���A��^16�i�� 
						string s = workspace[i+1] ;
						int t = 0 ;
						for( int i = s.size()-1 ; i >= 0 ; i-- ){
							int temp = s[t] - 48 ;
							location = location + temp*pow(16,i) ;
							t++ ;
						} // for

						c.loc = location ;
						c.opcode = "-1" ;
						//--------------------------------
						
					} // if
									
				} // if
				else if( workspace[i] == "LTORG" || workspace[i] == "END" ){
					c.loc = -1 ;
					c.opcode = "-1" ;
					
					for( int j = 0 ; j < 100 ; j++ ){
						
						if( Table7[j].symbol.empty() ) ;
						else{
							content tempc ;	
							tempc.loc = location ;
							if( Table7[j].address == -1 ){ //�N��literal���٨S�w�q��m 
								string s = Table7[j].symbol ;
								if( s[0] == '=' ) s = s.substr( 1, s.length()-1 ) ;
								
								if( IsaNum(s) ){ //���O�Ʀr�N�ئ�word 
									tempc.str = Table7[j].symbol + "WORD" ;
									tempc.opcode = s ;
									location = location + 3 ;
								} // if
								else{ //�ئ�byte
									tempc.str = Table7[j].symbol + "\t" + "BYTE" ;
									bool isNum  = IsaNum(s) ;
						
									if( isNum == true ){ //�O�Ʀr�i�H������W�h�A��ӼƦr�[�@��location 
										location = location + (s.size()+1)/2;
										tempc.opcode = s ;
									} // if
									else { //���O�Ʀr�N�O�r���A�����N�C�Ӧr��½machine code��X�� 
										location = location + s.size() ;
										
										string temp ;
										for( int j = 0 ; j < s.size() ; j++ ){
											char ss[100]={0} ;
											sprintf(ss, "%2x", (int)s[j] );
											temp = temp + ss ;
										} // of
										
										tempc.opcode = temp ;
										
									} // else
									
								} // else
								
								record.push_back(tempc) ;
							} // if
							
						} // else
						
					} // for
					
				} // else if
				else if( workspace[i] == "." ) { //comment line
					c.loc = -1 ;
					c.opcode = "-1" ;
					i = workspace.size() ;
				} // else if
				else if( FindPseudo( workspace[i] ) ){
					//�Opseudocode�����B�z �A�[½machine code 
					if( workspace[i] == "BYTE" ){
						if( i != 0 ) location = location - 3 ;
						string temp = workspace[i+1] ;
						
						if( temp[1] == '\'' ) {
							if( temp[0] == 'C' ){
								temp = temp.substr( 2, temp.length()-3 ) ;
								
								location = location + temp.size() ;
								string op = "" ;
								for( int j = 0 ; j < temp.size() ; j++ ){
									char s[100]={0} ;
									sprintf(s, "%2x", (int)temp[j] );
									op = op + s ;
								} // of
								c.opcode = op ;
							} // if
							else if( temp[0] == 'X' ){
								temp = temp.substr( 2, temp.length() - 3 ) ;
								
								location = location + (temp.size()+1)/2;
								c.opcode = temp ;
							} // else if
							else c.opcode = "Error Syntax!" ;
						} // if
						else{
							location = location + temp.size() ;
							string op = "" ;
							for( int j = 0 ; j < temp.size() ; j++ ){
								char s[100]={0} ;
								sprintf(s, "%02x", (int)temp[j] );
								op = op + s ;
							} // of
							c.opcode = op ;
						} // else
							
					} // if
					
					else if( workspace[i] == "WORD" ){
						if( i != 0 ) location = location - 3 ;
						//�Oword�N�ন6bit16�i��Alocation�����[3 
						string temp = workspace[i+1] ;
						if( temp[1] == '\'' ) {
							if( temp[0] == 'C' ){
								temp = temp.substr( 2, temp.length()-3 ) ;
								location = location + temp.size() ;
								string op = "" ;
								for( int j = 0 ; j < temp.size() ; j++ ){
									char s[100]={0} ;
									sprintf(s, "%06x", (int)temp[j] );
									op = op + s ;
								} // of
								c.opcode = op ;
							} // if
							else if( temp[0] == 'X' ){
								temp = temp.substr( 2, temp.length() - 3 ) ;
								location = location + (temp.size()+1)/2;
								c.opcode = temp ;
							} // else if
							else c.opcode = "Error Syntax!" ;
						} // if
						else{
							//�Oword�N�ন6bit16�i��Alocation�����[3 
							int t = StringtoInt( workspace[i+1] ) ;
							char s[100]={0} ;
							sprintf(s, "%06x", t );
							location = location + 3 ;
							c.opcode = s ;
						} // else
					} // else if
					else if( workspace[i] == "RESW" ){
						if( i != 0 ) location = location - 3 ;
						//�O�d�Ŷ��A�]���Oword�ҥH�n3�� 
						int t = StringtoInt( workspace[i+1] ) ;
						location = location + 3 * t ;
						c.opcode = "-1" ;
					} // else if
					else if( workspace[i] == "RESB" ){
						if( i != 0 ) location = location - 3 ;
						int t = StringtoInt( workspace[i+1] ) ;
						location = location + t ;
						c.opcode = "-1" ;
					} // else if
								
					i = workspace.size() ; //�B�̧�pseudo code���������o��A���ΦA½�F 
				} // else if
				else if( FindResgister(workspace[i]) ) ;
				else if( IsaNum(workspace[i]) ) ;
				else{ //�bstart�᭱���{���X�i�H�}�l��pass1 
					if( workspace[i][0] == '+' || workspace[i][0] == '#' ) ; 
					//+���N��instruction�A#�N��immediate addressing ��̳����Ωw�� 
					else if( FindInstruction(workspace[i]) ){
						if( i == 0 ) location = location + 3 ;
					}
					else{ //symbol 
						if( i == 0 ){ //0���i���1.�w�qsymbol or literal address 2.instruction 
									//2�b�W���B�� 	
									
							if( FindLiteral( workspace[i] ) ) SetLiteral( workspace[i], location ) ;
							//�Oliteral�N�h�]�wliteral address 	
							else{
								bool duplicate = true ;
								duplicate = SetSymbol( workspace[i], location ) ;
								//duplicate =false�N���w��
								if( duplicate == false ) c.opcode = "There is a duplicate symbol!!!" ;
								 
							} // else 
							
							location = location + 3 ;
						} // if
						else {
							
							if( workspace[i][0] == '=' ) SetLiteral( workspace[i], -1 ) ;
							else if( workspace[i][0] == '\'' ){
								string k = workspace[i] ;
								k = k.substr( 1, k.length() - 2 ) ;
								SetLiteral( workspace[i], -1 ) ;
							} // else if
							else SetSymbol( workspace[i], -1 ) ; //��L���s��symbol 
								
						} // else
						
					} // else
					
				} // else
						
			} // for
			
			
			record.push_back(c) ;	
		} // Pass1
		
		void Pass2(){
			
			bool ChangeOpcode = false, OpcodeDone = false ;
			string Opcode1 = "", Opcode2 = "" ;
			for( int i = 0 ; i < workspace.size() ; i++ ){
				if( start == false ){ //�٨S�}�l�L�A�n��M"start"
					if( workspace[i] == "START" ) start = true ;
					
					OpcodeDone = true ;
				} // if
				else if( workspace[i] == "END" || workspace[i] == "." ) OpcodeDone = true ;
				
				else if( FindPseudo( workspace[i] ) ) OpcodeDone = true ;
				
				else if( FindResgister(workspace[i]) ){
					if( workspace[i] == "X" ) ChangeOpcode = true ;
				} // else if	
				else{ //�bstart�᭱���{���X�i�H�}�l��pass1 
					if( i == 0 ){
						if( FindInstruction( workspace[i] ) ) GetInstruction( workspace[i], Opcode1 );
					}
					else if( FindInstruction( workspace[i] ) ) GetInstruction( workspace[i], Opcode1 );
					else if( FindLiteral( workspace[i] ) ) GetLiteral( workspace[i], Opcode2 );
					else if( FindSymbol( workspace[i] ) ) GetSymbol( workspace[i], Opcode2 );	
					
				} // else
						
			} // for
			
			
			string Opcode ;
			if( Opcode1 != "" && Opcode2 == "" ) Opcode2 = "0000" ;
			Opcode = Opcode1 + Opcode2 ; 
			if( ChangeOpcode == true ){
				int a = Change16into10(Opcode[2]) ;
				bitset<4>num(a) ;	
				num = num.set(3) ;
				string t = Change2to16(num) ;
				Opcode[2] = t[0] ;
				
			} // if
			
			if( OpcodeDone == true ) ;
			else
				record[time].opcode = Opcode ;
			//cout << Opcode << endl;
		}
		
		int Change16into10( char a ){
			int ans = 0 ;
			if( a == '0' ) ans = 0 ;
			if( a == '1' ) ans = 1 ;
			if( a == '2' ) ans = 2 ;
			if( a == '3' ) ans = 3 ;
			if( a == '4' ) ans = 4 ;
			if( a == '5' ) ans = 5 ;
			if( a == '6' ) ans = 6 ;
			if( a == '7' ) ans = 7 ;
			if( a == '8' ) ans = 8 ;
			if( a == '9' ) ans = 9 ;
			if( a == 'A' || a == 'a' ) ans = 10 ;
			if( a == 'B' || a == 'b' ) ans = 11 ;
			if( a == 'C' || a == 'c' ) ans = 12 ;
			if( a == 'D' || a == 'd' ) ans = 13 ;
			if( a == 'E' || a == 'e' ) ans = 14 ;
			if( a == 'F' || a == 'f' ) ans = 15 ;
			
			return ans ;
		}
		
		bool IsaNum( string s ){
			bool isnum = false ;
			for( int i = 0 ; i < s.length() ; i++ ){
				if( s[i] <= '9' && s[i] >= '0' ) ;
				else if( s[i] >= 'a' && s[i] <= 'f' ) ;
				else if( s[i] >= 'A' && s[i] <= 'F' ) ;
				else return false ;
			} // for
			
			return true ;
		} //IsaNum()	
		
		int StringtoInt( string s ){
			int num = 0 ;
			int j = 0 ;
			for( int i = s.size()-1 ; i >= 0 ; i-- ){
				
				int temp = ( s[j] - 48 ) * pow(10,i) ;
				num = num + temp ;
				j++ ;
			} // for
			
			return num ;
		} // StringtoInt
		
		string Change2to16( bitset<4>num ){
			int sum = 0 ;
			for( int i = num.size()-1 ; i >= 0 ; i-- ){
				
				sum = sum + num[i] * pow(2,i) ;
						
			} // for
			
			char s[100] = {0} ;
			sprintf(s, "%1x", sum) ;
			string t = s ;
			
			return t ;
		} // Change2to16
		
		bool Delimeter( char temp ){//���ˬd���I����(�r��) 
			string tt ;
			tt.append( 1, temp ) ; //�N�r����r�� 
			for( int i = 0 ; i < Table4.size() ; i++ ){
				if( tt == Table4[i] ) return true ;
					
			} // for
			
			return false ;
		} // Check()
		
		bool Delimeter( string temp ){//���ˬd���I����(�r��) 
			for( int i = 0 ; i < Table4.size() ; i++ ){
				if( temp == Table4[i] ) return true ;
					
			} // for
			
			return false ;
		} // Check()
		
		bool FindInstruction( string str ){
			bool find = false ;
			//�B�̫��O
			if( str[0] == '+' ) str = str.substr( 1, str.length()-1 ) ; 
			string strlow = str ;
			for( int i = 0 ; i < str.length() ; i++ ){ //�N�r���ର�p�g 
				strlow[i] = tolower(str[i]) ;
			} // for
					
			for( int i = 0 ; i < Instable.size() ; i++  ){
				if( strlow == Instable[i].mnemonic ){
					find = true ;
					
				}  // if
			} // for
			
			return find ;
		} // FindInsturction()
		
		bool GetInstruction( string str, string &op ){
			bool find = false ;
			//�B�̫��O 
			if( str[0] == '+' ) str = str.substr( 1, str.length()-1 ) ;
				
			string strlow = str ;
			for( int i = 0 ; i < str.length() ; i++ ){ //�N�r���ର�p�g 
				strlow[i] = tolower(str[i]) ;
			} // for
			
			
			for( int i = 0 ; i < Instable.size() ; i++  ){
				if( strlow == Instable[i].mnemonic ){
					find = true ;
					op = Instable[i].opcode ;
						
				}  // if
			} // for
			
			return find ;
		} // GetInsturction()
		
		bool FindSymbol( string str ){
			
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
					
				if( Table5[sum].symbol.empty() ){ //�O�Ů檽����Jtable 
					return false ;
					
				} // if
				else if( Table5[sum].symbol == str ){ //���o��symbol 	
					set = true ;
					return true ;
					
				} // else
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // FindSymbol
		
		bool SetSymbol( string str, int loc ){
			
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
					
				if( Table5[sum].symbol.empty() ){ //�O�Ů檽����Jtable 
					Table5[sum].symbol = str ;
					Table5[sum].address = loc ;
					set = true ;
					return true ;
					
				} // if
				else if( Table5[sum].symbol == str ){ //���@�˪�symbol�N���w�q 
					if( Table5[sum].address == -1 ){
						Table5[sum].address = loc ;
						return true ;
					} // if
					else return false ;	
					set = true ;
					
				} // else
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // SetSymbol
		
		bool GetSymbol( string str, string &op ){
			
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
				if( Table5[sum].symbol == str ){ //�w�g�s�b�N���w�q 	
					set = true ;
					if( Table5[sum].address >= 0 ){
						
						char s[100]={0} ;
						sprintf(s, "%04x", Table5[sum].address );
						string temp = s ;
						
						op = temp ;
					} // if
					else op = "Undefine symbol!" ;
					return true ;
					
				} // if
				else if( Table5[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // GetSymbol
		
		bool GetIntSymbol( string str, int &op ){
			
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
				if( Table5[sum].symbol == str ){  
						
					set = true ;
					if( Table5[sum].address >= 0 ){
						op = Table5[sum].address ;
					} // if
					else return false ; //-1�O�S���w�q 
					
					return true ;
					
				} // if
				else if( Table5[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // GetIntSymbol
		
		bool FindLiteral( string str ){
			
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){	
				if( Table7[sum].symbol == str ){ 	
					set = true ;
					return true ;
				} // else
				else if( Table7[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // FindLiteral
		
		bool SetLiteral( string str, int loc ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
					
				if( Table7[sum].symbol.empty() ){ //�O�Ů檽����Jtable 
					Table7[sum].symbol = str ;
					Table7[sum].address = loc ;
					
					set = true ;
					return true ;
					
				} // if
				else if( Table7[sum].symbol == str ){ 	
					set = true ;
					Table7[sum].address = loc ;
					return true ;
					
				} // else
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // SetLiteral
		
		bool GetLiteral( string str, string &op ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			int run = 0 ;
			while( set == false || run < 100 ){
				if( Table7[sum].symbol == str ){ 	
					set = true ;
					if( Table7[sum].address >= 0 ){
						char s[100]={0} ;
						sprintf(s, "%04x", Table7[sum].address );
						string temp = s ;
						
						op = temp ;
					} // if
					
					
					return true ;
					
				} // if
				else if( Table7[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
				run++ ;
			} // while.
				
		} // GetLiteral
		
		bool GetIntLiteral( string str, int &op ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			int run = 0 ;
			while( set == false || run < 100 ){
				if( Table7[sum].symbol == str ){ 	
					set = true ;
					if( Table7[sum].address >= 0 ){
						op = Table7[sum].address ;
					} // if
					
					return true ;
					
				} // if
				else if( Table7[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
				run++ ;
			} // while.
				
		} // GetIntLiteral
		
		bool FindPseudo( string str ){
			for( int i = 0 ; i < Table2.size() ; i++  ){
				if( str == Table2[i] ) return true ;
					
			} // for
			
			return false ;
		} //FindPseudo
		
		bool FindResgister( string str ){
			string strb = str ;
			for( int i = 0 ; i < str.length() ; i++ ){ //�N�r���ର�j�g 
				strb[i] = toupper(str[i]) ;
			} // for
			
			for( int i = 0 ; i < Table3.size() ; i++  ){
				if( strb == Table3[i] ){
					return true ;
						
				}  // if
				
			} // for
			
			return false ;
		} //FindResgister
		
		bool GetResgister( string str, string &op ){
			string strb = str ;
			for( int i = 0 ; i < str.length() ; i++ ){ //�N�r���ର�p�g 
				strb[i] = toupper(str[i]) ;
			} // for
			
			for( int i = 0 ; i < Table3.size() ; i++  ){
				if( strb == Table3[i] ){
					stringstream ss ;
					ss << i ;
					string s = ss.str() ;
					op = s ;
					
					return true ;
						
				}  // if
				
			} // for
			
			return false ;
		} //GetResgister
		
		bool GetIntResgister( string str, int &op ){
			string strlow = str ;
			for( int i = 0 ; i < str.length() ; i++ ){ //�N�r���ର�p�g 
				strlow[i] = toupper(str[i]) ;
			} // for
			
			for( int i = 0 ; i < Table3.size() ; i++  ){
				if( str == Table3[i] ){
					op = i ;
					return true ;
				}  // if
				
			} // for
			
			return false ;
		} //GetIntResgister
		
		bool SetReal( string str, int loc ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
					
				if( Table6[sum].symbol.empty() ){ //�O�Ů檽����Jtable 
					Table6[sum].symbol = str ;
					Table6[sum].address = loc ;
					
					set = true ;
					return true ;
					
				} // if
				else if( Table6[sum].symbol == str ){ 	
					set = true ;
					Table6[sum].address = loc ;
					return true ;
					
				} // else
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // SetReal
		
		bool GetReal( string str, string &op ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			int run = 0 ;
			while( set == false || run < 100 ){
				if( Table6[sum].symbol == str ){ 	
					set = true ;
					if( Table6[sum].address >= 0 ){
						char s[100]={0} ;
						sprintf(s, "%04x", Table6[sum].address );
						string temp = s ;
						
						op = temp ;
					} // if
					
					
					return true ;
					
				} // if
				else if( Table6[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
				run++ ;
			} // while.
				
		} // GetReal
		
		bool GetIntReal( string str, int &op ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			int run = 0 ;
			while( set == false || run < 100 ){
				if( Table6[sum].symbol == str ){ 	
					set = true ;
					if( Table6[sum].address >= 0 ){	
						op = Table6[sum].address ;
					} // if
					
					
					return true ;
					
				} // if
				else if( Table6[sum].symbol.empty() ) return false ;
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
				run++ ;
			} // while.
				
		} // GetIntReal
		
		bool FindReal( string str ){
			int sum = 0 ;
			for( int i = 0 ; i < str.size() ; i++ ){
				sum = sum + (int)str[i] ;
				sum = sum % 100 ;
			} // for
				
			bool set = false ;
			while( set == false ){
					
				if( Table6[sum].symbol.empty() ){ //�O�Ů檽����Jtable 
					return false ;
					
				} // if
				else if( Table6[sum].symbol == str ){ //���o��symbol 	
					set = true ;
					return true ;
					
				} // else
				else sum = sum+1 ; //collsion occur
					
				sum = sum % 100 ;
			} // while.
				
		} // FindSymbol
		
		bool CheckSyntax(){
			for( int i = 0 ; i < workspace.size() ; i++ ){
				string s = workspace[i] ;
				int l = s.length() ;
				
				if( FindInstruction( workspace[i] ) ) isInstruction = true ;
				
				else if( FindLiteral( workspace[i] ) ) isLiteral = true ;
				else if( workspace[i][0] == '\'' && workspace[i][l-1] == '\'' ) isLiteral = true ;
				else if( workspace[i][0] == '\'' && workspace[i][l-1] != '\'' ) return false ;
				
				else if( FindSymbol( workspace[i] ) ) isSymbol = true ;
				else if( FindPseudo( workspace[i] ) ) isPseudo = true ;
				
			} // for
			
			if( isSymbol == true || isLiteral == true ) m = true ;
			
			if( m == true && isInstruction == true ) return true ;
			else if(  isInstruction == true )  return true ;
			else if( isPseudo ) return true ;
			else return false ;
		}  // CheckSyntax()
			
		void Writetxt(){
	        fstream outfile ;
	        string outfilename = "ANS_SIC_output.txt" ;
	        outfile.open(outfilename.c_str(), ios:: out ) ;
	        
	        outfile << "Line" << "\t" << "Loc " << "\t"	<< "Source statement" << "\t" <<"Object code" << "\n" ;
	        outfile << "\n" ;
			
			int line = 5 ;
	        for( int i = 0 ; i < record.size() ; i++ ){
	        	string temp = "" ;
	        	if( record[i].loc == -1 ) ;
	        	else{
	        		char s[100]={0} ;
					sprintf(s, "%04x", record[i].loc );
					temp = s ;
					for( int j = 0 ; j < temp.length() ; j++ ){
						if( temp[j] >= 'a' && temp[j] <= 'z' ) temp[j] = toupper(temp[j]) ;
								
					} // of
					
				} // else
	        	
				
				outfile << line << "\t" << temp << "\t" << record[i].str << "\t" ;
				
				
				if( record[i].opcode == "-1" ) outfile << "\n" ;
				else{
					for( int j = 0 ; j < record[i].opcode.length() ; j++ ){
						if( record[i].opcode[j] >= 'a' && record[i].opcode[j] <= 'z' ) 
							record[i].opcode[j] = toupper(record[i].opcode[j]) ;
					} // for
					
					outfile << record[i].opcode << "\n" ;
					
				} // else
				
				line = line + 5 ;
			}
	        
	        outfile.close() ;
		}
};

int main(){
	cout << "Begin" << endl;
	BuildTables t ;
	t.BuildTable() ;
	
	BuildInstable B ;
	B.Rule() ;
	
	Run R ;
	//G.Test() ;
	R.Set() ;
	R.Begin() ;
	R.Gettoken() ;
	R.Gettoken() ;
	R.Writetxt() ;
	cout << "END" << endl;

}
