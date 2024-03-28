//tableau dynamique

#include <stdlib.h>
#include <stdio.h>


//le struct n'est qu'une liste d'attribut d'un objet, mais ces attributs ne sont pas initialis�s
typedef struct IntArray {

	int* pContent; //init le pContent � 0 (lorsque =0 il faut mettre NULL vu que c'est un pointeur)

	int iSize; //Commence � 0
	int iCapacity; //iCapacity li� � pContent, si pContent = NULL alors iCapacity = 0 etc. Utilis� lors du malloc ---> (int*)malloc(sizeof(int) * iCapacity; 

}IntArray;

//struct IntArray test_array = { .pContent = 5, .iSize = 10, .iCapacity = 200 };



//Initialisation des attributs de la struct IntArray
void Init(IntArray *pIntArray) {
	pIntArray->pContent = NULL; // pointeur de pointeur, hors c'est pas le cas, fail
	pIntArray->iCapacity = 0;
	pIntArray->iSize = 0;
}

//pas vraiment compris le diff�rence entre cette fonction et Insert, juste retenu que je peux utiliser Insert dans Add et que c'est une histoire de quand �a ajoute la case ????
//Add un Index ?
void Add(IntArray* pIntArray, int iValue) {

	int pIndex = 1;
	//malloc
	int* pIntArray = (int*)malloc(sizeof(int) * pIndex);
	Insert(pIntArray, iValue, pIndex); //prendre les adresses ?
	pIndex++; //vu que c'est dans une boucle for �a augmentera l'index de 1 � chaque tour de boucle
}


// du coup c'est l� qu'on insert chaque nouveaux input apr�s avoir fait add qui ne s'occupe que de la m�moire ? r�ponse NON apparemment
void Insert(IntArray* pIntArray, int iValue, int iIndex) {

	
	printf("Entrez un nombre entier � ajouter dans le tableau : ");
	scanf_s("%d", iValue);

	pIntArray->pContent[iIndex] = iValue;

}

//faire l'inverse d'Insert 
void Remove(IntArray* pIntArray, int iIndex) {

	AskIntBorne(pIntArray, iIndex);
	
}

int Get(IntArray *pIntArray, int iIndex) {

}

void Print(IntArray* pIntArray) {

	for (int i = 0; i < pIntArray->iSize; i++) {

		printf("%d", pIntArray->pContent);

	}
}



void AskIntBorne(IntArray *pIntArray, int maxIndex) {

	int deletedCase;
	printf("Voulez-vous supprimer une case du tableau ? Donnez le num�ro de la case correspondant : ");
	scanf_s("%d", &maxIndex);
	while (1) {

		if (0 <= deletedCase <= maxIndex) {

			pIntArray->pContent[deletedCase] = NULL;
			break;
		}
	}
}

//avec un free ? ou le free se fait plut�t dans la fonction Destroy ?

void Destroy(IntArray* pIntArray) {
	free(pIntArray->pContent);
}

int main() {

	IntArray array;
	Init(&array); // doublon.pContent: []

	Add(&array, 0); // doublon.pContent: [0]
	Add(&array, 5); // doublon.pContent: [0, 5]

	Printf(&array); //=> 0 5

	Destroy(&array);
	return 0;
}