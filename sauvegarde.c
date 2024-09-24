#include "game.h"

void sauvegarder(Personne p, Background b, Ennemi e) 
{
	FILE *fichier;
	save s;
	s.p = p;
	s.b = b;
	s.e = e;
	fichier = fopen("chargement", "wb");
	
	if (fichier != NULL)
	{
		fwrite(&s, sizeof(save), 1, fichier);
		printf("Jeu sauvegardé");
	}
	else 
	{
		printf("Erreur");
	}
	
	fclose(fichier);
}

int charger(Personne *p, Background *b, Ennemi *e)
{
	FILE *fichier;
	save s;
	fichier = fopen("chargement", "rb");
	fread(&s, sizeof(save), 1, fichier);
	fclose(fichier);

	p->pos.x = s.p.pos.x;
	p->pos.y = s.p.pos.y;
	p->pos_sprite.x = s.p.pos_sprite.x;
	p->pos_sprite.y = s.p.pos_sprite.y;
	p->vitesse = s.p.vitesse;
	p->acceleration = s.p.acceleration;
	p->direction = s.p.direction;
	p->up = s.p.up;

	e->pos1.x = s.e.pos1.x;
	e->pos1.y = s.e.pos1.y;
	e->pos2.x = s.e.pos2.x;
	e->pos2.y = s.e.pos2.y;
	e->direction = s.e.direction;
	e->etat = s.e.etat;
	e->num = s.e.num;

	b->camera.x = s.b.camera.x;
	b->camera.y = s.b.camera.y;
	b->camera2.x = s.b.camera2.x;
	b->camera2.y = s.b.camera2.y;

	printf("Chargement du personnage et du background");
}
