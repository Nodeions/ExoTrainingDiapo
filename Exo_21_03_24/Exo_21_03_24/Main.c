//tableau dynamique

#include <stdlib.h>
#include <stdio.h>


//le struct n'est qu'une liste d'attribut d'un objet, mais ces attributs ne sont pas initialisés
typedef struct IntArray {

	int* pContent; //init le pContent à 0 (lorsque =0 il faut mettre NULL vu que c'est un pointeur)

	int iSize; //Commence à 0
	int iCapacity; //iCapacity lié à pContent, si pContent = NULL alors iCapacity = 0 etc. Utilisé lors du malloc ---> (int*)malloc(sizeof(int) * iCapacity; 

}IntArray;

//struct IntArray test_array = { .pContent = 5, .iSize = 10, .iCapacity = 200 };



//Initialisation des attributs de la struct IntArray
void Init(IntArray *pIntArray) {
	pIntArray->pContent = NULL; // pointeur de pointeur, hors c'est pas le cas, fail
	pIntArray->iCapacity = 0;
	pIntArray->iSize = 0;
}

//pas vraiment compris le différence entre cette fonction et Insert, juste retenu que je peux utiliser Insert dans Add et que c'est une histoire de quand ça ajoute la case ????
//Add un Index ?
void Add(IntArray* pIntArray, int iValue) {

	int pIndex = 1;
	//malloc
	int* pIntArray = (int*)malloc(sizeof(int) * pIndex);
	Insert(pIntArray, iValue, pIndex); //prendre les adresses ?
	pIndex++; //vu que c'est dans une boucle for ça augmentera l'index de 1 à chaque tour de boucle
}


// du coup c'est là qu'on insert chaque nouveaux input après avoir fait add qui ne s'occupe que de la mémoire ? réponse NON apparemment
void Insert(IntArray* pIntArray, int iValue, int iIndex) {

	
	printf("Entrez un nombre entier à ajouter dans le tableau : ");
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
	printf("Voulez-vous supprimer une case du tableau ? Donnez le numéro de la case correspondant : ");
	scanf_s("%d", &maxIndex);
	while (1) {

		if (0 <= deletedCase <= maxIndex) {

			pIntArray->pContent[deletedCase] = NULL;
			break;
		}
	}
}

//avec un free ? ou le free se fait plutôt dans la fonction Destroy ?

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