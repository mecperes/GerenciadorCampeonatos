#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>
#include <string.h>
#include <time.h>

//-------------------------------------//
//Criação de Structs

struct TpTipoJogos{
	int codigo;
	char desc[30];
	char flag;
};

struct TpParticipantes{
	int codigo;
	char desc[30];
	char flag;
};

struct TpCampeonatos{
	int codigo;
	char titulo[30];
	char responsavel[30];
	int ano;
	int codigoJogo;
	char desc[70];
	char flag;
};

struct TpControle{
	int codigoCampeonato;
	int codParticipante;
	char nick[30];
	char flag;
};

//-------------------------------------//
//Declarar funçoes no scopo

void Moldura(int ci,int li,int cf,int lf,int cortxt, int corfundo);
void linha(int l,int ci,int cf,int cortxt,int corfundo);
char MenuGeral(void);
void Limpa(void);
void Apaga(void);
void CadastroTipoJogos(void);
int BuscaExaustiva_TpTipoJogos_cod(FILE *PtrArq,int cod);
int BuscaExaustiva_TpTipoJogos_desc(FILE *PtrArq,char desc[30]);
void ConsultaTipoJogos(void);
void RelatorioTipoJogos(void);
void RelatorioTipoJogos_flag(void);
void InsercaoDireta_cod(FILE *PtrArq);
void ExclusaoLogica_TipoJogos(void);
void ExclusaoFisica_TipoJogos(void);
int BuscaIndexada_TpParticipantes_cod(FILE *PtrArq,int cod);
void CadastroParticipantes(void);
void BubbleSort_Participantes(FILE *PtrArq);
void RelatorioParticipantes(void);
void RelatorioParticipantes_flag(void);
void CadastroCampeonatos(void);
int BuscaBinaria_Campeonatos_cod(FILE *PtrArq,int cod);
void RelatorioCapeonatos(void);
void SelecaoDireta_Campeonatos_cod(FILE *PtrArq);
void CadastroControle(void);
void RelatorioControle(void);
void RelatorioCapeonatos_flag(void);
int BuscaSentinela_Controle_CodigoDuplo(FILE *PtrArq,int CC,int CP);
void ConsultaParticipantes(void);
void ConsultaCampeonatos(void);
void RelatorioControle_flag(void);
void ExclusaoFisica_Participantes(void);
void ExclusaoFisica_Campeonatos(void);
void ExclusaoFisica_Controle(void);
void Alteracao_TipoJogos(void);
void Alteracao_Participantes(void);
void ExclusaoLogica_Participantes(void);
void Alteracao_Campeonatos(void);
void ConsultaControle(void);
void ExclusaoLogica_Campeonatos(void);
void ExclusaoFisica_Controle_DentroConsulta(void);
void AlteracaoControle(void);
void ExclusaoLogica_Controle(void);
void Relatorio_Um(void);
void Relatorio_Dois(void);
void BubbleSort_Participantes_nome(FILE *PtrArq);


//-------------------------------------//
//funcoes

void Moldura(int ci,int li,int cf,int lf,int cortxt, int corfundo){
	
	int i;
	
	textcolor(cortxt);
	textbackground(corfundo);
	gotoxy(ci,li); printf("%c",201);
	gotoxy(cf,li); printf("%c",187);
	gotoxy(ci,lf); printf("%c",200);
	gotoxy(cf,lf); printf("%c",188);
	
	for(i=ci+1;i<cf;i++){
		gotoxy(i,li); printf("%c",205);
		gotoxy(i,lf); printf("%c",205);
		
	}
	
	for(i=li+1;i<lf;i++){
		gotoxy(ci,i); printf("%c",186);
		gotoxy(cf,i); printf("%c",186);
		
	}
	
	textcolor(7);
	textbackground(0);
	
	
}

void Linha(int l,int ci,int cf,int cortxt,int corfundo){
	
	int i;
	
	textcolor(cortxt);
	textbackground(corfundo);
	
	for(i=ci;i<=cf;i++){
	gotoxy(i,l); 
	printf("%c",205);
	}
							
	textcolor(7);
	textbackground(0);
}

void Limpa(void){
	
	int a,b;
	
	for(a=2;a<25;a++)
		for(b=2;b<80;b++){	
			gotoxy(b,a); printf(" ");
		}									
}

void Apaga(void){
	
	int a,b;
	
	for(a=5;a<25;a++)
		for(b=2;b<80;b++){	
			gotoxy(b,a); printf(" ");
		}									
}
	
char MenuGeral(void){
	
	Limpa();
	gotoxy(30,3); printf("GERENCIADOR DE GAMES"); Linha(4,30,49,7,0);
	
	gotoxy(4,6); printf("Tipo de Jogos %c",25);
	gotoxy(10,7); printf("%c Cadastro    [ A ]",16);
	gotoxy(10,8); printf("%c Consulta    [ B ]",16);
	gotoxy(10,9); printf("%c Alteracao   [ C ]",16);
	gotoxy(10,10); printf("%c Relatorio   [ D ]",16);
	gotoxy(10,11); printf("%c Exclusao L  [ E ]",16);
	gotoxy(10,12); printf("%c Exclusao FL [ F ]",16);
	gotoxy(10,13); printf("%c Flag       [ F1 ]",16);
	
	gotoxy(4,15); printf("Participantes %c",25);
	gotoxy(10,16); printf("%c Cadastro    [ G ]",16);
	gotoxy(10,17); printf("%c Consulta    [ H ]",16);
	gotoxy(10,18); printf("%c Alteracao   [ I ]",16);
	gotoxy(10,19); printf("%c Relatorio   [ J ]",16);
	gotoxy(10,20); printf("%c Exclusao L  [ K ]",16);
	gotoxy(10,21); printf("%c Exclusao FL [ L ]",16);
	gotoxy(10,22); printf("%c Flag        [ F2 ]",16);
	
	gotoxy(34,6); printf("Campeonatos %c",25);
	gotoxy(40,7); printf("%c Cadastro    [ M ]",16);
	gotoxy(40,8); printf("%c Consulta    [ N ]",16);
	gotoxy(40,9); printf("%c Alteracao   [ O ]",16);
	gotoxy(40,10); printf("%c Relatorio   [ P ]",16);
	gotoxy(40,11); printf("%c Exclusao L  [ Q ]",16);
	gotoxy(40,12); printf("%c Exclusao FL [ R ]",16);
	gotoxy(40,13); printf("%c Flag        [ F3 ]",16);
	
	gotoxy(34,15); printf("Controle %c",25);
	gotoxy(40,16); printf("%c Cadastro    [ S ]",16);
	gotoxy(40,17); printf("%c Consulta    [ T ]",16);
	gotoxy(40,18); printf("%c Alteracao   [ U ]",16);
	gotoxy(40,19); printf("%c Relatorio   [ V ]",16);
	gotoxy(40,20); printf("%c Exclusao L  [ W ]",16);
	gotoxy(40,21); printf("%c Exclusao FL [ X ]",16);
	gotoxy(40,22); printf("%c Flag        [ F4 ]",16);
	
	gotoxy(62,13); printf("Relatorios ");
	gotoxy(63,14); printf("Especiais %c",25);	
	gotoxy(63,15); printf("%c Rel 1[ Y ]",16);
	gotoxy(63,16); printf("%c Rel 2[ Z ]",16);
	
	gotoxy(79,24);
	
	return toupper(getch());
	
}

void CadastroCampeonatos(void){
	
	int i,pos,pos2,a;
	TpCampeonatos aux;
	TpTipoJogos auxjog;
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	
	if(PtrCam == NULL || PtrJog == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		gotoxy(30,3); printf("Campeonatos - CADASTRO"); Linha(4,30,51,7,0);
	
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
		scanf("%d",&i);
		
		
		
		while(i>0){
		
			pos = BuscaBinaria_Campeonatos_cod(PtrCam,i);
		
		
			if(pos!=-1){
			
				Apaga();
				gotoxy(25,13); printf("Este codigo de jogo ja existe!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
			
			}
			else{
				Apaga();
				gotoxy(15,13); printf("Digite o titulo do campeonato: ");
				fflush(stdin); gets(aux.titulo);
				Apaga();
				gotoxy(15,13); printf("Digite o responsavel do campeonato: ");
				fflush(stdin); gets(aux.responsavel);
				Apaga();
				gotoxy(25,13); printf("Digite o ano do campeonato: ");
				scanf("%d",&aux.ano);
				
				Apaga();
				gotoxy(65,24); printf(" %c 0 = Sair",16);
				gotoxy(25,13); printf("Digite o codigo do jogo: ");
				scanf("%d",&a);
				
				while(a>0){
					
					pos2 = BuscaExaustiva_TpTipoJogos_cod(PtrJog,a);
					
					if(pos2 == -1){
						
						Apaga();
						gotoxy(25,13); printf("Codigo de jogo nao encontrado!");
						gotoxy(70,24); printf(" %c ENTER",16);
						getch();
						Apaga();
						gotoxy(65,24); printf(" %c 0 = Sair",16);
						gotoxy(25,13); printf("Digite o codigo do jogo: ");
						scanf("%d",&a);
						
					}
					else{
						
						Apaga();
						gotoxy(25,13); printf("Digite uma breve descricao do campeonato");
						gotoxy(10,14); printf("%c",16);
						fflush(stdin); gets(aux.desc);
						
						aux.codigo = i;
						
						fseek(PtrJog,pos2,0);
						fread(&auxjog,sizeof(TpTipoJogos),1,PtrJog);
						aux.codigoJogo = auxjog.codigo;
						aux.flag = 'A';
						fseek(PtrCam,0,2);
						fwrite(&aux,sizeof(TpCampeonatos),1,PtrCam);
						a=0;
						SelecaoDireta_Campeonatos_cod(PtrCam);
						Apaga();
						gotoxy(70,24); printf(" %c ENTER",16);
						gotoxy(15,13); printf("Cadastro Realizado com sucesso!");
						getch();								
						
					}
					
				}
																	
			}
			
			Apaga();	
			gotoxy(65,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
			scanf("%d",&i);
					
			
		}
		
		fclose(PtrCam);
		fclose(PtrJog);
	}
}


	void RelatorioCapeonatos(void){
	
	TpCampeonatos aux;
	
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	
	
	
	if(PtrCam == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		gotoxy(30,3); printf("Campeonatos - RELATORIO"); Linha(4,30,52,7,0);
		
		fseek(PtrCam,0,0);
		fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
		
		while(!feof(PtrCam)){
		
			if(aux.flag == 'A'){
				
				Apaga();
				gotoxy(3,10); printf("*Codigo: %d // Titulo: %s ",aux.codigo,aux.titulo);
				gotoxy(3,11); printf("Responsavel: %s",aux.responsavel);
				gotoxy(3,12); printf("Ano da disputa: %d",aux.ano);
				gotoxy(3,13); printf("**Codigo do Jogo: %d",aux.codigoJogo);
				gotoxy(5,15); printf("%c Descricao: %s",16,aux.desc);
			
				fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
			
			if(!feof(PtrCam)){
				
				
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				
			}
			
			
			}
			else{
				
				fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
				
			}
			
								
			
														
		}
	
	gotoxy(50,24); printf("                          ");
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrCam);
				
		
	}
			
	
}

void RelatorioCapeonatos_flag(void){
	
	TpCampeonatos aux;
	
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	
	
	
	if(PtrCam == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		gotoxy(30,3); printf("Campeonatos - RELATORIO"); Linha(4,30,52,7,0);
		
		fseek(PtrCam,0,0);
		fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
		
		while(!feof(PtrCam)){
			
			gotoxy(3,10); printf("*Codigo: %d // Titulo: %s ",aux.codigo,aux.titulo);
			gotoxy(3,11); printf("Responsavel: %s",aux.responsavel);
			gotoxy(3,12); printf("Ano da disputa: %d",aux.ano);
			gotoxy(3,13); printf("**Codigo do Jogo: %d",aux.codigoJogo);
			gotoxy(5,15); printf("%c Descricao: %s",16,aux.desc);
			gotoxy(5,16); printf("Flag: -- %c -- ",aux.flag);
			
			
			fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
		
			if(!feof(PtrCam)){
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				Apaga();
			}
														
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrCam);
					
	}
				
}


int BuscaSentinela_Controle_CodigoDuplo(FILE *PtrArq,int CC,int CP){

	TpControle aux;
	int posreturn,newpos,bandeira;
	
	
	aux.codigoCampeonato = CC;
	aux.codParticipante = CP;
	aux.flag = 'A';
	
	 
	fseek(PtrArq,0,2);
	bandeira = ftell(PtrArq) + sizeof(TpControle);
	
	fwrite(&aux,sizeof(TpControle),1,PtrArq);
	
	fseek(PtrArq,0,0);
	fread(&aux,sizeof(TpControle),1,PtrArq);
	
	while(aux.codigoCampeonato!=CC || aux.codParticipante!=CP || aux.flag !='A')
		
		fread(&aux,sizeof(TpControle),1,PtrArq);
		
		
	posreturn = ftell(PtrArq);
		
	fseek(PtrArq,bandeira-sizeof(TpControle),0);
	fread(&aux,sizeof(TpControle),1,PtrArq);
	aux.flag = 'I';
	fseek(PtrArq,bandeira-sizeof(TpControle),0);
	fwrite(&aux,sizeof(TpControle),1,PtrArq);
	
	fseek(PtrArq,posreturn,0);						
	
	if(ftell(PtrArq) != bandeira)					
		return ftell(PtrArq) - sizeof(TpControle);	
	else		
		return -1;			
}





int BuscaBinaria_Campeonatos_cod(FILE *PtrArq,int cod){
	
	int inicio=0,fim,meio;
	TpCampeonatos aux;
	
	fseek(PtrArq,0,2);
	fim = (ftell(PtrArq) / sizeof(TpCampeonatos))- 1;
	meio = fim/2;
	fseek(PtrArq,meio*sizeof(TpCampeonatos),0);
	fread(&aux,sizeof(TpCampeonatos),1,PtrArq);
	
	while(inicio < fim && (cod!=aux.codigo||aux.flag =='I')){
		
		if(cod > aux.codigo)
			inicio = meio+1;
		else
			fim = meio-1;				
		
		meio = (inicio+fim)/2;
		fseek(PtrArq,meio*sizeof(TpCampeonatos),0);
		fread(&aux,sizeof(TpCampeonatos),1,PtrArq);
	}
	
	if(cod == aux.codigo && aux.flag !='I')
		return ftell(PtrArq) - sizeof(TpCampeonatos);
	else
		return -1;	
	
}

void CadastroControle(void){
	
	int i,ii,k,kk,f;
	TpControle aux;
	
	
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	
	if(PtrCon == NULL ||PtrCam == NULL || PtrPar == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();		
	}
	else{
		
		gotoxy(30,3); printf("Controle - CADASTRO"); Linha(4,30,53,7,0);
		
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
		scanf("%d",&i);
		
		while(i > 0){
			
			ii = BuscaBinaria_Campeonatos_cod(PtrCam,i);
			
			if(ii == -1){
				Apaga();
				gotoxy(25,13); printf("Campeonato nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
				
			}
			else{
				
				Apaga();
				gotoxy(65,24); printf(" %c 0 = Voltar",16);
				gotoxy(25,13); printf("Digite o codigo do participante: ");	
				scanf("%d",&k);
				
				while(k>0){
					
					kk = BuscaIndexada_TpParticipantes_cod(PtrPar,k);
					
					if(kk == -1){
						
						Apaga();
						gotoxy(25,13); printf("Participante nao encontrado!");
						gotoxy(70,24); printf(" %c ENTER",16);
						getch();
						
						Apaga();
						gotoxy(65,24); printf(" %c 0 = Voltar",16);
						gotoxy(25,13); printf("Digite o codigo do participante: ");	
						scanf("%d",&k);
																						
					}
					else{
						
						f = BuscaSentinela_Controle_CodigoDuplo(PtrCon,i,k);
						
						if(f != -1){
							
							Apaga();
							gotoxy(25,13); printf("Jogador ja cadastrado neste campeonato");
							gotoxy(70,24); printf(" %c ENTER",16);
							k=0;
							getch();
							
							
						}
						else{
							
							Apaga();
							gotoxy(25,13); printf("Digite o nick para o campeonato: ");	
							fflush(stdin); gets(aux.nick);
						
							aux.codigoCampeonato = i;
							aux.codParticipante = k;
							aux.flag = 'A';	
						
							fseek(PtrCon,0,2);
							fwrite(&aux,sizeof(TpControle),1,PtrCon);
						
							k=0;
						
							Apaga();
							gotoxy(70,24); printf(" %c ENTER",16);
							gotoxy(25,13); printf("Cadastro realizado!");	
							getch();
							
							
						}
																
						
					}																									
					
				}		
				
			}
				Apaga();		
				gotoxy(65,24); printf(" %c 0 = Voltar",16);
				gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
				scanf("%d",&i);
						
		}
		fclose(PtrCam);				
		fclose(PtrPar);
		fclose(PtrCon);
	}		
	ExclusaoFisica_Controle_DentroConsulta();
}





void CadastroTipoJogos(void){
	
	TpTipoJogos aux;
	int i,a,t;
	char menu;
	
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	
	if(PtrJog == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
	gotoxy(30,3); printf("Tipo de Jogos - CADASTRO"); Linha(4,30,53,7,0);
	
	gotoxy(65,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do jogo: ");	
	scanf("%d",&i);
	
	while(i>0){
			
		
		a = BuscaExaustiva_TpTipoJogos_cod(PtrJog,i);
		
		if(a!=-1){	
			Apaga();
			gotoxy(25,13); printf("Este codigo de jogo ja existe!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();	
		}
		else{
			Apaga();
			gotoxy(25,13); printf("Digite o nome do jogo: ");
			fflush(stdin); gets(aux.desc);
			aux.codigo=i;
			aux.flag='A';
			fseek(PtrJog,0,2);
			fwrite(&aux,sizeof(TpTipoJogos),1,PtrJog);
			InsercaoDireta_cod(PtrJog);
										
		}
		Apaga();
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite outro codigo do jogo: ");	
		scanf("%d",&i);
		
				
	}	
	fclose(PtrJog);		
	}
}

void CadastroParticipantes(void){
	
	TpParticipantes aux;
	int i,a,t;
	char menu;
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	
	if(PtrPar == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
	gotoxy(30,3); printf("Participantes - CADASTRO"); Linha(4,30,53,7,0);
	
	gotoxy(65,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do participante: ");	
	scanf("%d",&i);
	
	while(i>0){
			
		
		a = BuscaIndexada_TpParticipantes_cod(PtrPar,i);
		
		if(a!=-1){	
			Apaga();
			gotoxy(25,13); printf("Este codigo de participante ja existe!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();	
		}
		else{
			Apaga();
			gotoxy(25,13); printf("Digite o nome do participante: ");
			fflush(stdin); gets(aux.desc);
			aux.codigo=i;
			aux.flag='A';
			fseek(PtrPar,0,2);
			fwrite(&aux,sizeof(TpParticipantes),1,PtrPar);
			BubbleSort_Participantes(PtrPar);//InsercaoDireta_cod(PtrJog); ----> Precisa fazer outro metodo de insercao
										
		}
		Apaga();
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite outro codigo de participante: ");	
		scanf("%d",&i);
		
				
	}	
	fclose(PtrPar);		
	}
	
}

void BubbleSort_Participantes(FILE *PtrArq){
	
	TpParticipantes auxi,auxb;
	
	int i,TL;
	
	fseek(PtrArq,0,2);
	TL = ftell(PtrArq) / sizeof(TpParticipantes);
	
	
	while(TL > 1){
		
		for(i=0;i<TL-1;i++){
			
			fseek(PtrArq,i*sizeof(TpParticipantes),0);
			fread(&auxi,sizeof(TpParticipantes),1,PtrArq);
			fseek(PtrArq,(i+1)*sizeof(TpParticipantes),0);
			fread(&auxb,sizeof(TpParticipantes),1,PtrArq);
			
			if(auxi.codigo > auxb.codigo){
				
				fseek(PtrArq,i*sizeof(TpParticipantes),0);
				fwrite(&auxb,sizeof(TpParticipantes),1,PtrArq);
				fseek(PtrArq,(i+1)*sizeof(TpParticipantes),0);
				fwrite(&auxi,sizeof(TpParticipantes),1,PtrArq);	
					
			}
			
				
		}
		TL--;				
	}		
}

void BubbleSort_Participantes_nome(FILE *PtrArq){
	
	TpParticipantes auxi,auxb;
	
	int i,TL;
	
	fseek(PtrArq,0,2);
	TL = ftell(PtrArq) / sizeof(TpParticipantes);
	
	
	while(TL > 1){
		
		for(i=0;i<TL-1;i++){
			
			fseek(PtrArq,i*sizeof(TpParticipantes),0);
			fread(&auxi,sizeof(TpParticipantes),1,PtrArq);
			fseek(PtrArq,(i+1)*sizeof(TpParticipantes),0);
			fread(&auxb,sizeof(TpParticipantes),1,PtrArq);
			
			if(stricmp(auxi.desc,auxb.desc)==1){
				//auxi.desc > auxb.desc
				fseek(PtrArq,i*sizeof(TpParticipantes),0);
				fwrite(&auxb,sizeof(TpParticipantes),1,PtrArq);
				fseek(PtrArq,(i+1)*sizeof(TpParticipantes),0);
				fwrite(&auxi,sizeof(TpParticipantes),1,PtrArq);	
					
			}
			
				
		}
		TL--;				
	}		
}



void ExclusaoLogica_TipoJogos(void){
	
	int i,pos,pos2,m,TL,pos3;
	TpTipoJogos aux;
	char k;
	TpCampeonatos auxc;
	TpControle auxp;
	
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	
	if(PtrJog == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		gotoxy(30,3); printf("Tipo de Jogos - Exc Logica"); Linha(4,30,55,7,0);
		
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do jogo: ");	
		scanf("%d",&i);
		
		while(i>0){
			
			pos = BuscaExaustiva_TpTipoJogos_cod(PtrJog,i);
			
			if(pos==-1){
				Apaga();
				gotoxy(25,13); printf("Codigo de jogo nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();		
			}
			else{
				
				fseek(PtrJog,pos,0);
				fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
				Apaga();
				gotoxy(25,13); printf("Codigo valido!");
				gotoxy(25,15); printf("Codigo: %d // Nome: %s",aux.codigo,aux.desc);
				gotoxy(60,24); printf(" %c 'S'--> Sim'",16);
				gotoxy(40,24); printf(" %c 'N'--> Nao'",16);
				gotoxy(25,17); printf("Deseja realmente excluir?: "); fflush(stdin);
				
				k = toupper(getch());
				
				
				if(k == 'N'){
					Apaga();
					gotoxy(25,13); printf("Exclusao Cancelada");
					gotoxy(70,24); printf(" %c ENTER",16);
					getch();						
				}
				else{
															
					pos2=0;
					
					fseek(PtrCam,0,0);
					
					fread(&auxc,sizeof(TpCampeonatos),1,PtrCam);
						
					
					while(!feof(PtrCam)){
						
						
						if(auxc.codigoJogo == i){
							
							
							pos3=0;
							
							fseek(PtrCon,0,0);
							
							fread(&auxp,sizeof(TpControle),1,PtrCon);
							
							
							while(!feof(PtrCon)){
								
								
								if(auxc.codigo == auxp.codigoCampeonato){
									
									fseek(PtrCon,pos3*sizeof(TpControle),0);
									auxp.flag='I';
									fwrite(&auxp,sizeof(TpControle),1,PtrCon);
									fseek(PtrCon,(pos3+1)*sizeof(TpControle),0);
												
									
								}
								
								fread(&auxp,sizeof(TpControle),1,PtrCon);
								pos3++;
												
								
							}
													
							
							
							fseek(PtrCam,pos2*sizeof(TpCampeonatos),0);
							auxc.flag ='I';
							fwrite(&auxc,sizeof(TpCampeonatos),1,PtrCam);
							fseek(PtrCam,(pos2+1)*sizeof(TpCampeonatos),0);	// aq ó
						}
						
						
						fread(&auxc,sizeof(TpCampeonatos),1,PtrCam);
						pos2++;				
						
					}
						
					
					Apaga();		
					aux.flag='I';
					fseek(PtrJog,pos,0);
					fwrite(&aux,sizeof(TpTipoJogos),1,PtrJog);
					gotoxy(20,13); printf("O jogo %s foi excluido Logicamente",aux.desc);
					gotoxy(70,24); printf(" %c ENTER",16);
					getch();	
															
				}
														
			}
			
			Apaga();
			gotoxy(65,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do jogo: ");	
			scanf("%d",&i);	
		}		
											
		fclose(PtrJog);
		fclose(PtrCam);
		fclose(PtrCon);
	}				
}


void ExclusaoLogica_Participantes(void){
	
	TpParticipantes auxp;
	TpControle auxc;
	int pos,i,pos2;
	char k;
	
	
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	
	gotoxy(30,3); printf("Participantes - Exc Logica"); Linha(4,30,55,7,0);
		
	gotoxy(65,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do jogador: ");	
	scanf("%d",&i);
	
	while(i > 0){
		
		pos = BuscaIndexada_TpParticipantes_cod(PtrPar,i);
		
		if(pos == -1){
			Apaga();
			gotoxy(25,13); printf("Codigo de participante nao encontrado!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();
			
		}
		else{
			
			fseek(PtrPar,pos,0);
			fread(&auxp,sizeof(TpParticipantes),1,PtrPar);
			Apaga();
			gotoxy(25,13); printf("Codigo valido!");
			gotoxy(25,15); printf("Codigo: %d // Nome: %s",auxp.codigo,auxp.desc);
			gotoxy(60,24); printf(" %c 'S'--> Sim'",16);
			gotoxy(40,24); printf(" %c 'N'--> Nao'",16);
			gotoxy(25,17); printf("Deseja realmente excluir?: "); fflush(stdin);
			
			k = toupper(getch());
			
			if(k == 'N'){
				
				Apaga();
				gotoxy(25,13); printf("Exclusao Cancelada");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();	
				
			}
			else{
				
				fseek(PtrCon,0,0);
				
				pos2=ftell(PtrCon);
				
				fread(&auxc,sizeof(TpControle),1,PtrCon);
				
				while(!feof(PtrCon)){
					
					
					if(auxc.codParticipante == i){
						
						fseek(PtrCon,pos2,0);
						auxc.flag ='I';
						fwrite(&auxc,sizeof(TpControle),1,PtrCon);
						fseek(PtrCon,pos2+(1*sizeof(TpControle)),0);	// aq ó
						
						
					}
					
					fread(&auxc,sizeof(TpControle),1,PtrCon);
					pos2+=sizeof(TpControle);	
					
				}
				
				Apaga();		
				auxp.flag='I';
				fseek(PtrPar,pos,0);
				fwrite(&auxp,sizeof(TpParticipantes),1,PtrPar);
				gotoxy(20,13); printf("O jogador %s foi excluido Logicamente",auxp.desc);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
				
			}
							
			
		}
													
		Apaga();
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do jogador: ");	
		scanf("%d",&i);
		
		
	}
			
	fclose(PtrPar);
	fclose(PtrCon);
}

void ExclusaoLogica_Campeonatos(void){
	
	TpCampeonatos auxc;
	TpControle auxce;
	int pos,i,pos2;
	char k;
	
	
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	
	gotoxy(30,3); printf("Campeonatos - Exc Logica"); Linha(4,30,53,7,0);
		
	gotoxy(65,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
	scanf("%d",&i);
	
	while(i > 0){
		
		pos = BuscaBinaria_Campeonatos_cod(PtrCam,i);
		
		if(pos == -1){
			Apaga();
			gotoxy(25,13); printf("Codigo de campeonato nao encontrado!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();
			
		}
		else{
			
			fseek(PtrCam,pos,0);
			fread(&auxc,sizeof(TpCampeonatos),1,PtrCam);
			Apaga();
			gotoxy(25,13); printf("Codigo valido!");
			gotoxy(25,15); printf("Codigo: %d // titulo: %s",auxc.codigo,auxc.titulo);
			gotoxy(60,24); printf(" %c 'S'--> Sim'",16);
			gotoxy(40,24); printf(" %c 'N'--> Nao'",16);
			gotoxy(25,17); printf("Deseja realmente excluir?: "); fflush(stdin);
			
			k = toupper(getch());
			
			if(k == 'N'){
				
				Apaga();
				gotoxy(25,13); printf("Exclusao Cancelada");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();	
				
			}
			else{
				
				fseek(PtrCon,0,0);
				
				pos2=ftell(PtrCon);
				
				fread(&auxce,sizeof(TpControle),1,PtrCon);
				
				while(!feof(PtrCon)){
					
					
					if(auxce.codigoCampeonato == i){
						
						fseek(PtrCon,pos2,0);
						auxce.flag ='I';
						fwrite(&auxce,sizeof(TpControle),1,PtrCon);
						fseek(PtrCon,pos2+(1*sizeof(TpControle)),0);	// aq ó
						
						
					}
					
					fread(&auxce,sizeof(TpControle),1,PtrCon);
					pos2+=sizeof(TpControle);	
					
				}
				
				Apaga();		
				auxc.flag='I';
				fseek(PtrCam,pos,0);
				fwrite(&auxc,sizeof(TpCampeonatos),1,PtrCam);
				gotoxy(20,13); printf("O Campeonato %d foi excluido Logicamente",auxc.codigo);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
				
			}
							
			
		}
													
		Apaga();
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do Campeonato: ");	
		scanf("%d",&i);
		
		
	}
			
	fclose(PtrCam);
	fclose(PtrCon);
}


void RelatorioControle(void){
	
	TpControle aux;
	int i=6;
	
	FILE *PtrCon = fopen("Controle.dat","rb");
	
	
	if(PtrCon == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Controle - RELATORIO"); Linha(4,30,53,7,0);
			
		fread(&aux,sizeof(TpControle),1,PtrCon);		
			
			
		while(!feof(PtrCon)){
		
			
			if(aux.flag == 'A'){
				gotoxy(10,i); printf("*Codigo do campeonato: %d // Codigo do participante: %d",aux.codigoCampeonato,aux.codParticipante);
				gotoxy(10,i+1); printf("Nick: %s",aux.nick); 
				i+=2;
			}
			
			fread(&aux,sizeof(TpControle),1,PtrCon);
		
			if(i>=17){
				
				
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				Apaga();
				i=6;
			}
		
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrCon);
	
	}
}



void RelatorioControle_flag(void){
	
	TpControle aux;
	int i=6;
	
	FILE *PtrCon = fopen("Controle.dat","rb");
	
	
	if(PtrCon == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Controle - RELATORIO"); Linha(4,30,53,7,0);
			
		fseek(PtrCon,0,0);
			
		fread(&aux,sizeof(TpControle),1,PtrCon);		
			
			
		while(!feof(PtrCon)){
		
				
			gotoxy(10,i); printf("*Codigo do campeonato: %d // Codigo do participante: %d",aux.codigoCampeonato,aux.codParticipante);
			gotoxy(10,i+1); printf("Nick: %s // flag: -- %c --",aux.nick,aux.flag); 
			i+=2;
									
			
			fread(&aux,sizeof(TpControle),1,PtrCon);
		
			if(i>=17){
				
				
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				Apaga();
				i=6;
			}
		
		}
	
		gotoxy(65,24); printf(" %c ENTER",16);
		getch();
		
		fclose(PtrCon);
	
	}
}




void RelatorioTipoJogos(void){
	
	TpTipoJogos aux;
	int i=6;
	
	FILE *PtrJog = fopen("Jogos.dat","rb");
	
	
	if(PtrJog == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Tipo de Jogos - RELATORIO"); Linha(4,30,54,7,0);
			
		fread(&aux,sizeof(TpTipoJogos),1,PtrJog);		
			
			
		while(!feof(PtrJog)){
		
			if(aux.flag == 'A'){
			gotoxy(20,i); printf("*Codigo: %d // Nome: %s",aux.codigo,aux.desc);
			i++;
			}
			
			fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
		
			if(i==15){
				
				Apaga();
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				i=6;
			}
		
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrJog);
	
	}
}

void RelatorioParticipantes(void){
	
	TpParticipantes aux;
	int i=6;
	
	FILE *PtrPar = fopen("Participantes.dat","rb");
	
	
	if(PtrPar == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Participantes - RELATORIO"); Linha(4,30,54,7,0);
			
		fread(&aux,sizeof(TpParticipantes),1,PtrPar);		
			
			
		while(!feof(PtrPar)){
		
			if(aux.flag == 'A'){
			gotoxy(20,i); printf("*Codigo: %d // Nome: %s",aux.codigo,aux.desc);
			i++;
			}
			
			fread(&aux,sizeof(TpParticipantes),1,PtrPar);
		
			if(i==15){
				
				Apaga();
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				i=6;
			}
		
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrPar);
	
	}
	
}

void RelatorioParticipantes_flag(void){
	
	TpTipoJogos aux;
	int i=6;
	
	FILE *PtrPar = fopen("Participantes.dat","rb");
	
	
	if(PtrPar == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Participantes - RELATORIO"); Linha(4,30,54,7,0);
			
		fread(&aux,sizeof(TpParticipantes),1,PtrPar);		
			
			
		while(!feof(PtrPar)){
		
			
			gotoxy(10,i); printf("*Codigo: %d // Nome: %s // Flag: `%c`",aux.codigo,aux.desc,aux.flag);
			i++;
			fread(&aux,sizeof(TpParticipantes),1,PtrPar);
		
			if(i==15){
				
				Apaga();
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				i=6;
			}
		
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrPar);
	
	}
	
}

void ExclusaoFisica_TipoJogos(void){
	
	TpTipoJogos aux;
	
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	FILE *PtrNew = fopen("New.dat","wb");
	
	if(PtrJog == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
		
	}
	else{
	
	
		fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
	
		while(!feof(PtrJog)){
		
			if(aux.flag == 'A')
				fwrite(&aux,sizeof(TpTipoJogos),1,PtrNew);
			
		
			fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
		
		}
		
		fclose(PtrNew);	
		fclose(PtrJog);
		remove("Jogos.dat");
		rename("New.dat","Jogos.dat");				
		gotoxy(30,3); printf("Tipo de Jogos - Exc Fisica"); Linha(4,30,55,7,0);
		gotoxy(25,13); printf("Exclusao fisica realizada!");	
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();	
	
	
	}
	
}

void ExclusaoFisica_Controle(void){
	
	TpControle aux;
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	FILE *PtrNew = fopen("New.dat","wb");
	
	if(PtrCon == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
		
	}
	else{
	
	
		fread(&aux,sizeof(TpControle),1,PtrCon);
	
		while(!feof(PtrCon)){
		
			if(aux.flag == 'A')
				fwrite(&aux,sizeof(TpControle),1,PtrNew);
			
		
			fread(&aux,sizeof(TpControle),1,PtrCon);
		
		}
		
		fclose(PtrNew);	
		fclose(PtrCon);
		remove("Controle.dat");
		rename("New.dat","Controle.dat");				
		gotoxy(30,3); printf("Tipo de Jogos - Exc Fisica"); Linha(4,30,53,7,0);
		gotoxy(25,13); printf("Exclusao fisica realizada!");	
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();	
	
	}
	
}

void ExclusaoFisica_Controle_DentroConsulta(void){
	
	TpControle aux;
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	FILE *PtrNew = fopen("New.dat","wb");
	
	if(PtrCon == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
		
	}
	else{
	
	
		fread(&aux,sizeof(TpControle),1,PtrCon);
	
		while(!feof(PtrCon)){
		
			if(aux.flag == 'A')
				fwrite(&aux,sizeof(TpControle),1,PtrNew);
			
		
			fread(&aux,sizeof(TpControle),1,PtrCon);
		
		}
		
		fclose(PtrNew);	
		fclose(PtrCon);
		remove("Controle.dat");
		rename("New.dat","Controle.dat");				
								
	}
	
}



void ExclusaoFisica_Participantes(void){
	
	TpParticipantes aux;
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	FILE *PtrNew = fopen("New.dat","wb");
	
	if(PtrPar == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
		
	}
	else{
	
	
		fread(&aux,sizeof(TpParticipantes),1,PtrPar);
	
		while(!feof(PtrPar)){
		
			if(aux.flag == 'A')
				fwrite(&aux,sizeof(TpParticipantes),1,PtrNew);
			
		
			fread(&aux,sizeof(TpParticipantes),1,PtrPar);
		
		}
		
		fclose(PtrNew);	
		fclose(PtrPar);
		remove("Participantes.dat");
		rename("New.dat","Participantes.dat");				
		gotoxy(30,3); printf("Participantes - Exc Fisica"); Linha(4,30,55,7,0);
		gotoxy(25,13); printf("Exclusao fisica realizada!");	
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();	
	
	
	}
	
}







void ExclusaoFisica_Campeonatos(void){
	
	TpCampeonatos aux;
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrNew = fopen("New.dat","wb");
	
	if(PtrCam == NULL){
		Apaga();
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
		
	}
	else{
	
	
		fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
	
		while(!feof(PtrCam)){
		
			if(aux.flag == 'A')
				fwrite(&aux,sizeof(TpCampeonatos),1,PtrNew);
			
		
			fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
		
		}
		
		fclose(PtrNew);	
		fclose(PtrCam);
		remove("Campeonatos.dat");
		rename("New.dat","Campeonatos.dat");				
		gotoxy(30,3); printf("Campeonatos - Exc Fisica"); Linha(4,30,53,7,0);
		gotoxy(25,13); printf("Exclusao fisica realizada!");	
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();	
	
	
	}
	
}


void RelatorioTipoJogos_flag(void){
	
	TpTipoJogos aux;
	int i=6;
	
	FILE *PtrJog = fopen("Jogos.dat","rb");
	
	
	if(PtrJog == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{	
		
		gotoxy(30,3); printf("Tipo de Jogos - RELATORIO"); Linha(4,30,54,7,0);
			
		fread(&aux,sizeof(TpTipoJogos),1,PtrJog);		
			
			
		while(!feof(PtrJog)){
		
			
			gotoxy(10,i); printf("*Codigo: %d // Nome: %s // Flag: `%c`",aux.codigo,aux.desc,aux.flag);
			i++;
			fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
		
			if(i==15){
				
				Apaga();
				gotoxy(55,24); printf(" %c Next Page[ENTER]",16);
				getch();
				i=6;
			}
		
		}
	
	gotoxy(65,24); printf(" %c ENTER",16);
	getch();
	
	fclose(PtrJog);
	
	}
}

void ConsultaTipoJogos(void){
	
	int pos;
	TpTipoJogos aux;
	int desc;
	
	FILE *PtrJog = fopen("Jogos.dat","rb");
	
	if(PtrJog == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Tipo de Jogos - CONSULTA"); Linha(4,30,53,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do jogo: ");
		scanf("%d",&desc);
		
		while(desc>0){
		
		pos = BuscaExaustiva_TpTipoJogos_cod(PtrJog,desc);
		
			if(pos == -1){
			
				Apaga();
				gotoxy(25,13); printf("Jogo nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{
			
				
				fseek(PtrJog,pos,0);
				fread(&aux,sizeof(TpTipoJogos),1,PtrJog);
				
				Apaga();
				gotoxy(25,13); printf("Jogo encontrado!");
				gotoxy(25,15); printf("*Codigo: %d",aux.codigo);
				gotoxy(26,16); printf("Nome: %s",aux.desc);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do jogo: ");
			scanf("%d",&desc);					
		
		}
		
		fclose(PtrJog);
	}	
				
}
void ConsultaCampeonatos(void){
		
	
	int pos;
	TpCampeonatos aux;
	int desc;
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb");
	
	if(PtrCam == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Campeonatos - CONSULTA"); Linha(4,30,51,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do Campeonato: ");
		scanf("%d",&desc);
		
		while(desc>0){
		
		pos = BuscaBinaria_Campeonatos_cod(PtrCam,desc);
		
			if(pos == -1){
			
				Apaga();
				gotoxy(25,13); printf("Campeonato nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{
			
				
				fseek(PtrCam,pos,0);
				fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
				
				Apaga();
				gotoxy(3,7); printf("Campeonato encontrado!");
				
				
				gotoxy(3,10); printf("*Codigo: %d // Titulo: %s ",aux.codigo,aux.titulo);
				gotoxy(3,11); printf("Responsavel: %s",aux.responsavel);
				gotoxy(3,12); printf("Ano da disputa: %d",aux.ano);
				gotoxy(3,13); printf("**Codigo do Jogo: %d",aux.codigoJogo);
				gotoxy(5,15); printf("%c Descricao: %s",16,aux.desc);
				
				
				
				
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do Campeonato: ");
			scanf("%d",&desc);					
		
		}
		
		fclose(PtrCam);
	}	
				
}
	
	
void Alteracao_Participantes(void){
	
	int pos,i;
	TpParticipantes aux;
	char auxi[30];
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	
	
		gotoxy(30,3); printf("Participantes - Alteracao"); Linha(4,30,54,7,0);
		
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do Participante: ");	
		scanf("%d",&i);
	
		while(i>0){
			
			pos = BuscaIndexada_TpParticipantes_cod(PtrPar,i);
			
			if(pos == -1){
				
				Apaga();
				gotoxy(25,13); printf("Participante nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
	
			}
			else{
				
				Apaga();
				
				gotoxy(20,13); printf("Digite o novo nome do Participante: "); fflush(stdin);	
				gets(auxi);
				fseek(PtrPar,pos,0);
				aux.flag='A';
				aux.codigo = i;
				strcpy(aux.desc,auxi);
				fwrite(&aux,sizeof(TpParticipantes),1,PtrPar);
				
				Apaga();
				gotoxy(25,13); printf("Alteracao realizada");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
								
				
			}
																				
			gotoxy(65,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do jogo: ");	
			scanf("%d",&i);
			
		}
		
	
	fclose(PtrPar);
	
}	


void Alteracao_Campeonatos(void){
	
	int pos,i,help,popo;
	TpCampeonatos aux;
	char auxi[30];
	char t;
	
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	
	
		gotoxy(30,3); printf("Campeonatos - Alteracao"); Linha(4,30,52,7,0);
		
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do Campeonato: ");	
		scanf("%d",&i);
	
		while(i>0){
			
			pos = BuscaBinaria_Campeonatos_cod(PtrCam,i);
			
			if(pos == -1){
				
				Apaga();
				gotoxy(25,13); printf("Campeonato nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
	
			}
			else{
				
				Apaga();
				gotoxy(20,9); printf("Alteracao: ");
				gotoxy(20,10); printf("[ A ] Titulo");
				gotoxy(20,11); printf("[ B ] Responsavel");
				gotoxy(20,12); printf("[ C ] Ano");
				gotoxy(20,13); printf("[ D ] Jogo");
				gotoxy(20,14); printf("[ E ] Descricao");
				gotoxy(20,15); printf("[ESC] SAIR");
				
				t = toupper(getch());
				fseek(PtrCam,pos,0);
				fread(&aux,sizeof(TpCampeonatos),1,PtrCam);
				
				while(t!=27){
					
					
					
					switch(t){
						
						case 'A':
							
							Apaga();
							gotoxy(25,13); printf("Digite o novo titulo: "); fflush(stdin);
							gets(aux.titulo);
							Apaga();
							gotoxy(25,13); printf("Titulo alterado!"); fflush(stdin);
							gotoxy(70,24); printf(" %c ENTER",16);
							getch();										
							break;
							
							
						case 'B':
							
							Apaga();
							gotoxy(25,13); printf("Digite o novo responsavel: "); fflush(stdin);
							gets(aux.responsavel);
							Apaga();
							gotoxy(25,13); printf("Responsavel alterado!"); fflush(stdin);
							gotoxy(70,24); printf(" %c ENTER",16);
							getch();										
							break;
							
							
							break;
						
						case 'C':
							
							Apaga();
							gotoxy(25,13); printf("Digite o novo ano: "); 
							scanf("%d",&aux.ano);
							Apaga();
							gotoxy(25,13); printf("Ano alterado!"); fflush(stdin);
							gotoxy(70,24); printf(" %c ENTER",16);
							getch();																					
							break;
									
						case 'D':
							
							Apaga();
							gotoxy(65,24); printf(" %c 0 = Voltar",16);
							gotoxy(25,13); printf("Digite o codigo do novo jogo: "); 
							scanf("%d",&help);
							
							while(help>0){
								
								popo = BuscaExaustiva_TpTipoJogos_cod(PtrJog,help);
								
								if(popo == -1){
									
									Apaga();
									gotoxy(25,13); printf("Jogo nao encontrado!");
									gotoxy(70,24); printf(" %c ENTER",16);
									getch();	
									
								}
								else{
									
									 
									aux.codigoJogo = help;
									Apaga();
									gotoxy(25,13); printf("Jogo alterado!"); fflush(stdin);
									gotoxy(70,24); printf(" %c ENTER",16);
									getch();																					
									break;
																							
									
								}
																																
								Apaga();
								gotoxy(65,24); printf(" %c 0 = Voltar",16);
								gotoxy(25,13); printf("Digite o codigo do novo jogo: "); 
								scanf("%d",&help);
									
							}
							break;
							
							
						case 'E':
							Apaga();
							gotoxy(25,13); printf("Digite a nova descricao: "); fflush(stdin);
							gets(aux.desc);
							Apaga();
							gotoxy(25,13); printf("Descricao alterada!"); fflush(stdin);
							gotoxy(70,24); printf(" %c ENTER",16);
							getch();										
							break;
							
							
							break;	
						
																							
						
					}
							
								
											
					Apaga();
					gotoxy(20,9); printf("Alteracao: ");
					gotoxy(20,10); printf("[ A ] Titulo");
					gotoxy(20,11); printf("[ B ] Responsael");
					gotoxy(20,12); printf("[ C ] Ano");
					gotoxy(20,13); printf("[ D ] Jogo");
					gotoxy(20,14); printf("[ E ] Descricao");
					gotoxy(20,15); printf("[ESC] SAIR");
					
					t = toupper(getch());							
					
					
					
				}
				
				fseek(PtrCam,pos,0);
				fwrite(&aux,sizeof(TpCampeonatos),1,PtrCam);
												
			}
			Apaga();																
			gotoxy(65,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do campeonato: ");	
			scanf("%d",&i);
			
		}
		
	
	fclose(PtrCam);
	fclose(PtrJog);
	
}

	
	
	
	
void Alteracao_TipoJogos(void){
	
	int pos,i;
	TpTipoJogos aux;
	char auxi[30];
	
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	
	
		gotoxy(30,3); printf("Jogos - Alteracao"); Linha(4,30,46,7,0);
		
		gotoxy(65,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do jogo: ");	
		scanf("%d",&i);
	
		while(i>0){
			
			pos = BuscaExaustiva_TpTipoJogos_cod(PtrJog,i);
			
			if(pos == -1){
				
				Apaga();
				gotoxy(25,13); printf("Jogo nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				
	
			}
			else{
				
				Apaga();
				
				gotoxy(25,13); printf("Digite o novo nome do jogo: "); fflush(stdin);	
				gets(auxi);
				fseek(PtrJog,pos,0);
				aux.flag='A';
				aux.codigo = i;
				strcpy(aux.desc,auxi);
				fwrite(&aux,sizeof(TpTipoJogos),1,PtrJog);
				
				Apaga();
				gotoxy(25,13); printf("Alteracao realizada");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
								
				
			}
																				
			gotoxy(65,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do jogo: ");	
			scanf("%d",&i);
			
		}
		
	
	fclose(PtrJog);
	
}	
		


void ConsultaParticipantes(void){
	
	int pos;
	TpParticipantes aux;
	int desc;
	
	FILE *PtrPar = fopen("Participantes.dat","rb");
	
	if(PtrPar == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Participantes - CONSULTA"); Linha(4,30,53,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do participante: ");
		scanf("%d",&desc);
		
		while(desc>0){
		
		pos = BuscaIndexada_TpParticipantes_cod(PtrPar,desc);
		
			if(pos == -1){
			
				Apaga();
				gotoxy(25,13); printf("Participante nao encontrado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{
			
				
				fseek(PtrPar,pos,0);
				fread(&aux,sizeof(TpParticipantes),1,PtrPar);
				
				Apaga();
				gotoxy(25,13); printf("Participante encontrado!");
				gotoxy(25,15); printf("*Codigo: %d",aux.codigo);
				gotoxy(26,16); printf("Nome: %s",aux.desc);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do Participante: ");
			scanf("%d",&desc);					
		
		}
		
		fclose(PtrPar);
	}	
				
}

void ConsultaControle(void){
	
	int pos;
	TpControle aux;
	int cc,cp;
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	if(PtrCon == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Consulta - CONSULTA"); Linha(4,30,53,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");
		scanf("%d",&cc);
		
		
		while(cc>0){
			
			Limpa();
			
			gotoxy(25,13); printf("Digite o codigo do participante: ");
			scanf("%d",&cp);
		
			pos = BuscaSentinela_Controle_CodigoDuplo(PtrCon,cc,cp);
		
			
			if(pos == -1){
			
				Apaga();
				gotoxy(15,13); printf("Campeonato e Participante inserido nao relacionado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{
			
				
				fseek(PtrCon,pos,0);
				fread(&aux,sizeof(TpControle),1,PtrCon);
				
				Apaga();
				gotoxy(25,13); printf("Consulta verificada!");
				gotoxy(25,15); printf("*Codigo Campeonato: %d",aux.codigoCampeonato);
				gotoxy(25,16); printf("*Codigo Participante: %d",aux.codParticipante);
				gotoxy(26,17); printf("Nick: %s",aux.nick);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do campeonato: ");
			scanf("%d",&cc);					
		
		}
		
		fclose(PtrCon);
	}
		
	ExclusaoFisica_Controle_DentroConsulta();			
}

void AlteracaoControle(void){
	
	int pos;
	TpControle aux;
	int cc,cp;
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	if(PtrCon == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Alteracao - CONSULTA"); Linha(4,30,53,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");
		scanf("%d",&cc);
		
		
		while(cc>0){
			
			Apaga();
			
			gotoxy(25,13); printf("Digite o codigo do participante: ");
			scanf("%d",&cp);
		
			pos = BuscaSentinela_Controle_CodigoDuplo(PtrCon,cc,cp);
		
			
			if(pos == -1){
			
				Apaga();
				gotoxy(15,13); printf("Campeonato e Participante inserido nao relacionado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{			
				
				fseek(PtrCon,pos,0);
				fread(&aux,sizeof(TpControle),1,PtrCon);
				
				Apaga();
				gotoxy(25,13); printf("Digite o novo nick do jogador: "); fflush(stdin);
				gets(aux.nick);
				
				fseek(PtrCon,pos,0);
				fwrite(&aux,sizeof(TpControle),1,PtrCon);
				
				
				Apaga();
				gotoxy(25,13); printf("Nick alterado!"); 
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do campeonato: ");
			scanf("%d",&cc);					
		
		}
		
		fclose(PtrCon);
	}
		
	ExclusaoFisica_Controle_DentroConsulta();			
}

void ExclusaoLogica_Controle(void){
	
	int pos;
	TpControle aux;
	int cc,cp;
	char k;
	
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	if(PtrCon == NULL){
		gotoxy(25,13); printf("Arquivo ERROR");
		gotoxy(70,24); printf(" %c ENTER",16);
		getch();
	}
	else{
		
		Apaga();
		gotoxy(30,3); printf("Controle - EXCLUSAO LOG"); Linha(4,30,53,7,0);
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");
		scanf("%d",&cc);
		
		
		while(cc>0){
			
			Apaga();
			
			gotoxy(25,13); printf("Digite o codigo do participante: ");
			scanf("%d",&cp);
		
			pos = BuscaSentinela_Controle_CodigoDuplo(PtrCon,cc,cp);
		
			
			if(pos == -1){
			
				Apaga();
				gotoxy(15,13); printf("Campeonato e Participante inserido nao relacionado!");
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();					
			
			}
			else{			
				
				fseek(PtrCon,pos,0);
				fread(&aux,sizeof(TpControle),1,PtrCon);
				Apaga();
				gotoxy(25,13); printf("Codigo valido!");
				gotoxy(25,15); printf("Codigo Campeonato: %d",aux.codigoCampeonato);
				gotoxy(25,16); printf("Codigo Participante: %d",aux.codParticipante);
				gotoxy(25,17); printf("Nick: %s",aux.nick);
				gotoxy(60,24); printf(" %c 'S'--> Sim'",16);
				gotoxy(40,24); printf(" %c 'N'--> Nao'",16);
				gotoxy(25,19); printf("Deseja realmente excluir?: "); fflush(stdin);
			
				k = toupper(getch());
				
				
				if(k =='N'){
					
					Apaga();
					gotoxy(25,13); printf("Exclusao Cancelada");
					gotoxy(70,24); printf(" %c ENTER",16);
					getch();
						
				}
				else{
					
					fseek(PtrCon,pos,0);
					aux.flag='I';
					Apaga();
					fseek(PtrCon,pos,0);
					fwrite(&aux,sizeof(TpControle),1,PtrCon);
					gotoxy(25,13); printf("Exclusao logica realizada!"); 
					gotoxy(70,24); printf(" %c ENTER",16);
					getch();
																							
					
				}
																												
			}
			
			Apaga();
			gotoxy(60,24); printf(" %c 0 = Voltar",16);
			gotoxy(25,13); printf("Digite o codigo do campeonato: ");
			scanf("%d",&cc);					
		
		}
		
		fclose(PtrCon);
	}
		
				
}


void SelecaoDireta_Campeonatos_cod(FILE *PtrArq){
	
//	for(int i=0;i<n-1;i++){
//    	menor_idx = i;
//    	for(int j= i+1;j<n;j++){
//        	if(vet[menor_idx] > vet[j]) menor_idx =j;
//    	}
//    	if(menor_idx!=i){
//        	//troca
//    	}
//}

	TpCampeonatos auxa,auxb;
	int menor_idx,TL;
		
	fseek(PtrArq,0,2);
	TL = ftell(PtrArq) / sizeof(TpCampeonatos) ; 
	
	for(int i=0; i<TL-1 ; i++){
		
		menor_idx = i;
		
		for(int j=i+1;j<TL;j++){
			
			fseek(PtrArq,menor_idx*sizeof(TpCampeonatos),0);
			fread(&auxa,sizeof(TpCampeonatos),1,PtrArq);
			fseek(PtrArq,j*sizeof(TpCampeonatos),0);
			fread(&auxb,sizeof(TpCampeonatos),1,PtrArq);
			
			if(auxa.codigo > auxb.codigo)
				menor_idx = j;		
				
		}
		
		if(menor_idx!=i)
			fseek(PtrArq,i*sizeof(TpCampeonatos),0);
			fread(&auxa,sizeof(TpCampeonatos),1,PtrArq);
			fseek(PtrArq,menor_idx*sizeof(TpCampeonatos),0);
			fread(&auxb,sizeof(TpCampeonatos),1,PtrArq);
			fseek(PtrArq,menor_idx*sizeof(TpCampeonatos),0);
			fwrite(&auxa,sizeof(TpCampeonatos),1,PtrArq);
			fseek(PtrArq,i*sizeof(TpCampeonatos),0);
			fwrite(&auxb,sizeof(TpCampeonatos),1,PtrArq);		
			
	}
		
}





int BuscaExaustiva_TpTipoJogos_cod(FILE *PtrArq,int cod){
	
	TpTipoJogos aux;
	
	fseek(PtrArq,0,0);
	
	fread(&aux,sizeof(TpTipoJogos),1,PtrArq);
	
	while(!feof(PtrArq) && (aux.codigo!=cod||aux.flag=='I'))
		
		fread(&aux,sizeof(TpTipoJogos),1,PtrArq);
	
	if(!feof(PtrArq))
		return ftell(PtrArq) - sizeof(TpTipoJogos);
	else
		return -1;	
}




int BuscaIndexada_TpParticipantes_cod(FILE *PtrArq,int cod){
	
	TpParticipantes aux;
	
	fseek(PtrArq,0,0);
	
	fread(&aux,sizeof(TpParticipantes),1,PtrArq);
	
	while(!feof(PtrArq) && (cod>aux.codigo||aux.flag=='I'))
		
		fread(&aux,sizeof(TpParticipantes),1,PtrArq);
	
	
	if(cod==aux.codigo && aux.flag!='I')
		return ftell(PtrArq) - sizeof(TpParticipantes);
	else
		return -1;	
}

void InsercaoDireta_cod(FILE *PtrArq){
	
	TpTipoJogos auxi,auxb;
	
	int TL,i;
	
	fseek(PtrArq,0,2);
	TL = ftell(PtrArq) / sizeof(TpTipoJogos);
	i=TL-1;
	
	fseek(PtrArq,(i-1)*sizeof(TpTipoJogos),0);
	fread(&auxb,sizeof(TpTipoJogos),1,PtrArq);
	fread(&auxi,sizeof(TpTipoJogos),1,PtrArq);
	
	while(i>0 && auxi.codigo < auxb.codigo){
		
		fseek(PtrArq,(i-1)*sizeof(TpTipoJogos),0);
		fwrite(&auxi,sizeof(TpTipoJogos),1,PtrArq);
		fwrite(&auxb,sizeof(TpTipoJogos),1,PtrArq);
		
		i--;
		
		fseek(PtrArq,(i-1)*sizeof(TpTipoJogos),0);
		fread(&auxb,sizeof(TpTipoJogos),1,PtrArq);
		fread(&auxi,sizeof(TpTipoJogos),1,PtrArq);
		
	}
}

void Relatorio_Um(void){
	
	int cp,pospar,contfora,contdentro,i;
	TpTipoJogos auxj;
	TpParticipantes auxp;
	TpControle auxcon;
	TpCampeonatos auxcam;
	
	
	
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	
	gotoxy(65,3); printf("RELATORIO 1"); 
	gotoxy(60,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do Participante: ");
	scanf("%d",&cp);
	
	while(cp > 0){
		
		pospar = BuscaIndexada_TpParticipantes_cod(PtrPar,cp);
		
		
		if(pospar == -1){
			
			Apaga();
			gotoxy(25,13); printf("Jogador nao encontrado!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();
			
		}
		else{
			
			fseek(PtrPar,pospar,0);
			fread(&auxp,sizeof(TpParticipantes),1,PtrPar);
			gotoxy(5,3); printf("Jogador Selecionado: %s",auxp.desc);
			
			contfora=0;
			fseek(PtrJog,0,0);
			fread(&auxj,sizeof(TpTipoJogos),1,PtrJog);
			
			while(!feof(PtrJog)){
				
				i=8;
				
				if(auxj.flag == 'A'){
				
					contdentro=0;
					
					Apaga();
					gotoxy(5,6); printf("%c %s",16,auxj.desc);
					
					fseek(PtrCam,0,0);
					fread(&auxcam,sizeof(TpCampeonatos),1,PtrCam);
					
					while(!feof(PtrCam)){
						
						if(auxj.codigo==auxcam.codigoJogo && auxcam.flag == 'A'){
							
							fseek(PtrCon,0,0);
							fread(&auxcon,sizeof(TpControle),1,PtrCon);
							
							while(!feof(PtrCon)){
							
								if(auxcam.codigo == auxcon.codigoCampeonato && auxp.codigo == auxcon.codParticipante && auxcon.flag == 'A'){
									
								gotoxy(10,i);	printf("Titulo: %s // Resp: %s // Nick: %s",auxcam.titulo,auxcam.responsavel,auxcon.nick);
								contdentro++;
								contfora++;
								i++;
									
									
								}
							
								fread(&auxcon,sizeof(TpControle),1,PtrCon);
							
							}
							
						
						}
										
						fread(&auxcam,sizeof(TpCampeonatos),1,PtrCam);
					
					}
				}
				
				gotoxy(7,24); printf("Total de camp do game: %d",contdentro);
				gotoxy(45,24); printf("Total geral: %d",contfora);
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
				fread(&auxj,sizeof(TpTipoJogos),1,PtrJog);
			}
				Apaga();
				gotoxy(25,13); printf("Quantidade total de campeonatos: %d",contfora); 
				gotoxy(70,24); printf(" %c ENTER",16);
				getch();
								
											
			
		}
														
		Limpa();
		gotoxy(65,3); printf("RELATORIO 1"); 
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do Participante: ");
		scanf("%d",&cp);	
		
	}
	
	fclose(PtrJog);
	fclose(PtrCam);
	fclose(PtrCon);
	fclose(PtrPar);	
	
}

void Relatorio_Dois(void){
	
	int cc,poscamp,posjog,i,poscon,contdentro=0;
	TpTipoJogos auxj;
	TpParticipantes auxp;
	TpControle auxcon;
	TpCampeonatos auxcam;
	
	FILE *PtrPar = fopen("Participantes.dat","rb+");
	FILE *PtrJog = fopen("Jogos.dat","rb+");
	FILE *PtrCam = fopen("Campeonatos.dat","rb+");
	FILE *PtrCon = fopen("Controle.dat","rb+");
	
	BubbleSort_Participantes_nome(PtrPar);
	
	gotoxy(65,3); printf("RELATORIO 2"); 
	gotoxy(60,24); printf(" %c 0 = Voltar",16);
	gotoxy(25,13); printf("Digite o codigo do campeonato: ");
	scanf("%d",&cc);
	
	while(cc>0){
		
		poscamp = BuscaBinaria_Campeonatos_cod(PtrCam,cc);
		
		
		if(poscamp == -1){
			
			Apaga();
			gotoxy(25,13); printf("Campeonato nao encontrado!");
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();
			
		}
		else{
			
			
			fseek(PtrCam,poscamp,0);
			fread(&auxcam,sizeof(TpCampeonatos),1,PtrCam);
			
			posjog = BuscaExaustiva_TpTipoJogos_cod(PtrJog,auxcam.codigoJogo);
			
			fseek(PtrJog,posjog,0);
			fread(&auxj,sizeof(TpTipoJogos),1,PtrJog);
			
			Apaga();
			gotoxy(5,2); printf("%c %s",16,auxcam.titulo);
			gotoxy(5,3); printf("%s --- %d --- %s",auxcam.responsavel,auxcam.ano,auxj.desc);
			gotoxy(5,4); printf("Descricao: %s",auxcam.desc);
			
			i=7;
			
			fseek(PtrPar,0,0);
			fread(&auxp,sizeof(TpParticipantes),1,PtrPar);
			
			while(!feof(PtrPar)){
				
				poscon = BuscaSentinela_Controle_CodigoDuplo(PtrCon,cc,auxp.codigo);
				
				if(poscon != -1){
					
				gotoxy(7,i);	printf("%c %s",16,auxp.desc);
				i++;	
				contdentro++;	
				}
										
				
				fread(&auxp,sizeof(TpParticipantes),1,PtrPar);
				
			}
			
			
			
			gotoxy(5,20); printf("Quantidade total de participantes: %d",contdentro); 
			gotoxy(70,24); printf(" %c ENTER",16);
			getch();
									
			
		}
		Limpa();
		gotoxy(65,3); printf("RELATORIO 2"); 
		gotoxy(60,24); printf(" %c 0 = Voltar",16);
		gotoxy(25,13); printf("Digite o codigo do campeonato: ");
		scanf("%d",&cc);
	}
	
				
	ExclusaoFisica_Controle_DentroConsulta();
	BubbleSort_Participantes(PtrPar);
	fclose(PtrJog);
	fclose(PtrCam);
	fclose(PtrCon);
	fclose(PtrPar);	
	
}




//-------------------------------------//
//int main

int main(void){
	
	char menu;
	
	FILE *PtrArq1 = fopen("Jogos.dat","ab");
	fclose(PtrArq1);
	FILE *PtrArq2 = fopen("Participantes.dat","ab");
	fclose(PtrArq2);
	FILE *PtrArq3 = fopen("Campeonatos.dat","ab");
	fclose(PtrArq3);
	FILE *PtrArq4 = fopen("Controle.dat","ab");
	fclose(PtrArq4);
	

	
	while(menu!=27){
		
		Moldura(1,1,80,25,0,6);
		menu = MenuGeral();

		switch(menu){
				
			case 'A':
				Limpa();
				CadastroTipoJogos();
				break;
			
			case 'B':
				Limpa();
				ConsultaTipoJogos();			
				break;
				
			case 'C':
				Limpa();
				Alteracao_TipoJogos();
				break;	
				
			case 'D':
				Limpa();
				RelatorioTipoJogos();
				break;
				
			case 59: //F1
				Limpa();
				RelatorioTipoJogos_flag();	
				break;
				
			case 'E':
				Limpa();
				ExclusaoLogica_TipoJogos();
				break;
				
			case 'F':
				Limpa();
				ExclusaoFisica_TipoJogos();	
				break;
			
			case 'G':
				Limpa();
				CadastroParticipantes();
				break;	
				
			case 'J':
				Limpa();
				RelatorioParticipantes();
				break;
				
			case 60: //F2
				Limpa();
				RelatorioParticipantes_flag();	
				break;
				
			case 'M':
				Limpa();
				CadastroCampeonatos();
				break;					
				
			case 'P':
				Limpa();
				RelatorioCapeonatos();
				break;	
				
			case 'S':
				Limpa();
				CadastroControle();
				break;	
				
			case 'V':
				Limpa();
				RelatorioControle();
				break;
				
			case 61: //F3
				Limpa();
				RelatorioCapeonatos_flag();	
				break;	
				
			case 'H':
				Limpa();
				ConsultaParticipantes();
				break;	
				
			case 'N':
				Limpa();
				ConsultaCampeonatos();
				break;															
					
			case 62: //f4
				Limpa();
				RelatorioControle_flag();
				break;				
				
			case 'L':
				Limpa();
				ExclusaoFisica_Participantes();
				break;		
				
			case 'R':
				Limpa();
				ExclusaoFisica_Campeonatos();
				break;	
					
					
			case 'X':
				Limpa();
				ExclusaoFisica_Controle();
				break;
				
			case 'I':
				Limpa();
				Alteracao_Participantes();
				break;	
					
			case 'K':
				Limpa();
				ExclusaoLogica_Participantes();	
				break;
			case 'O':
				Limpa();
				Alteracao_Campeonatos();
				break;
				
			case 'Q':
				Limpa();
				ExclusaoLogica_Campeonatos();
				break;	
				
			case 'T':
				Limpa();
				ConsultaControle();
				break;	
				
			case 'U':
				Limpa();
				AlteracaoControle();
				break;
				
			case 'W':
				Limpa();
				ExclusaoLogica_Controle();
				break;	
					
			case 'Y':
				Limpa();
				Relatorio_Um();		
				break;
				
			case 'Z':
				Limpa();
				Relatorio_Dois();
				break;	
		}
	}
}


//-------------------------------------//
