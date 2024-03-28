#include "CollisionsTiles.h"
#include "Charmander.h"
#include "BattleLayer.h"

bool CollisionsTiles::shouldSpawnPokemon()
{
    // Generamos un número aleatorio entre 0 y 1
   double randomValue = static_cast<double>(rand()) / RAND_MAX;

    // 30% de probabilidad que aparezca
    double spawnProbability = 0.001;

    // Compara el valor aleatorio con la probabilidad
    return randomValue < spawnProbability;
}

void CollisionsTiles::colissionGrass(Actor* player,list<Tile*> grass_tiles,Game* game)
{
    for (auto const& grass : grass_tiles) {
        if (player->vx != 0 || player->vy != 0) {
            if (player->isOverlap(grass, 0)) {
                if (shouldSpawnPokemon()) {
                    std::cout << "Spawnea Pokémon. Iniciando batalla..." << std::endl;
                    Pokemon* wildPokemon = Pokemon::generateRandomPokemon(game);
                    game->layer = game->battleLayer;
                    list<Pokemon*> list;
                    list.push_back(Pokemon::generateRandomPokemon(game));
                    if (dynamic_cast<BattleLayer*>(game->layer) != nullptr) {
                        BattleLayer* battleLayer = dynamic_cast<BattleLayer*>(game->layer);
                        battleLayer->initializeBattle(list,wildPokemon);
                    }
                   
                }
            }
        }
        
    }
}
