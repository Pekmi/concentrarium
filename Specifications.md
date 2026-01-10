*(J'écris en fr par flemme, faudra faire le README en anglais par contre, ça fait plus pro. On peut même le rédiger en plusieurs langues, ça serait classe.)*

***Cahier des charges du projet :***


**Charges techniques :**
- Doit pouvoir tourner avec un minimum de 2 Go de RAM (4 Go si ce n'est pas possible avec 2 Go).
- Doit fonctionner sans accès à un serveur : le projet tourne en local, utilisant uniquement la RAM et le stockage de la machine l'utilisant. De la RAM virtuelle sera utilisée pour certains éléments afin de ne pas surcharger la RAM.

**Fonctionnalités prévues :**

- Choix initiaux de l'utilisateur :
  - Allocation RAM et de mémoire.
  - Conditions de départ : Humidité, luminosité, température. **(À compléter si besoin)**
  - Éléments de départ : types de mousses et de champignons présents, topologie du terrain. (option "aléatoire" possible)
  - Caractéristiques de la fourmilière : placement, taille, comportement initial. (option "aléatoire" possible)
  - Bannissement de certaines évolutions possibles : Caractères génétiques des plantes ou champignons, comportements des fourmis.

- Interactions possibles par l'utilisateur :
  - Changement de la vitesse d'évolution : Aucune, 1x, 2x...
  - Changement des conditions : Humidité, luminosité, température. **(À compléter si besoin)**
  - Changement de caméra : vue d'ensemble, caméra libre, suivi d'une fourmi.
  - Options de son : augmenter, baisser, couper le volume.
  - Options d'affichage : augmenter, baisser la luminosité d'affichage (différente de celle des conditions de simulation); changer la taille de la fenêtre; afficher le concentrarium sur le fond d'écran.
  - Choix de si l'évolution continue lorsque le Concentrarium n'est pas lancé.
  - Sauvegarde d'états du Concentrarium sous la forme de fichiers simples à modifier.

- Fonctionnalités automatisées du Concentrarium :
  - Évolution du terrain avec le temps et selon les conditions environnementales.
  - Évolution de l'IA comportementale des fourmis. **(Et de leur ADN si vous voulez)**
  - Évolution du code génétique des matières organiques : Mousses et Champignons.
