#include <iostream>

using namespace std;

int main()
{
	/*##################################*/
	/*     MISE EN PLACE DES OBJETS     */
	/*##################################*/

	// 1. Creer un routeur
	

	// 2. Creer une maison, avec l'ID 1, une adresse et la position 14.0.
	// Ajouter la maison aux connexions du routeur
	

	//3. Creer un objet Meteo et ajouter la maison a sa liste d'observateurs.
	// Ajouter ensuite les villes Montreal, Toronto et New York
	// Avec les températures respectivent 21, 15 et 22
	

	// 4. Creer 4 personnes: Philippe Lafrite, Mathilde Lafrite, Francois Lerigolo et Florence Lerigolo
	// Avec les preferences en gouts respectivement neutre, salé, sucré et salé
	// Ajouter une allergie alimentaire au "Arachides" pour Florence
	

	
	// 5. Creer un cellulaire pour chaque occupant (IDs: 2, 3, 4 et 5)
	// Ajouter la maison dans la liste des observateurs de chaque cellulaire.
	
	// 6. Modifier la position des cellulaires de Philippe, Mathilde, Francois et Florence
	// a 7, 8, 6, 5 respectivement
	

	// 7. Ajouter Philippe et Mathilde comme occupants de la maison
	// Lorsqu'on ajoute un occupant a la maison, son cellulaire doit egalement etre ajoute.
	
	// 9. Créer 2 chauffages dont 1 automatiques et les connecter au routeur
	// Attention à ne pas leur attribuer des IDs similaires aux IDs déjà attribués(commencer à 5)
	

	// 10. Créer un frigo avec un ID de 10, puis connectez le au routeur.
	// Ajouter dans le frigo les aliments suivants :
	/*
	Pomme		Sucre
	Poule		Sale
	Yogourt		Sucre
	Dattes		Sucre
	Beurre		Neutre
	Arachides	Sale
	*/

	/*##################################*/
	/*           TEST GENERAL           */
	/*##################################*/

	
	// 1. Placer les cellulaires de Philippe et Mathilde aux positions 12.0 et 13.0 respectivement
	cout << "Philippe et Mathilde arrivent a la maison" << endl;
	

	// 2. Changer la temperature exterieure de Montreal a 24 degres (en utilisant l'objet Meteo)
	// ReChanger la temperature exterieure de Montreal a 18 degres
	// Changer la temperature exterieure de Toronto a 22 degres
	cout << endl << "Changement de temperature Montreal : 24" << endl;
	
	cout << endl << "Changement de temperature Montreal : 18" << endl;
	
	cout << endl << "Changement de temperature Toronto : 22" << endl;
	

	// 3. Placer le cellulaire de Francois à la position 15.0
	cout << endl << "Francois arrive" << endl;
	

	// 4. Placer le cellulaire de Florence à la position 15.0
	cout << endl << "Florence arrive" << endl;
	

	// 5. Sans envoyer de message, utilisez directement l'objet Frigo pour afficher le menu 
	//	que Mathilde et Florence peuvent manger en commun
	cout << endl << "Les aliments que Mathilde et Florence peuvent manger et apprecier ensemble sont:" << endl;
	
	
	// 6. Francois décide de manger une pomme et Florence des amandes.
	// Retirez les du frigo.
	cout << "\nFrancois et Florence decident de manger\n";
	
	// 7. Placer les cellulaires loin de la maison (position 20.0 par exemple)
	cout << endl << "Tout le monde quitte la maison" << endl;
	
	// 8. Pour mieux vérifier les méthodes de tri, ajouter Francois et Florence
	//	  comme occupants à la maison,
	
	// 9. Trier les occupants selon leurs noms. Puis trier les occupants selon leurs ages

	/*#############*/
	/*     FIN     */
	/*#############*/
	cout << endl;

	// 1. Desallocation de la memoire.
	
	
	return 0;
}