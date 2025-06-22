#pragma once

enum class Type {
    None,
    Normal,
    Fire,
    Water,
    Grass,
    Electric,
    Ice,
    Fighting,
    Poison,
    Ground,
    Flying,
    Psychic,
    Bug,
    Rock,
    Ghost,
    Dragon,
    Dark,
    Steel,
    Fairy
};

enum class Nature { //Numerical values are defined based on which stat is raised/lowered
    //values where x//5 = y raise the y+1 stat
    // Values where x % 5 = y lower the y+1 stat
    // Since adamant=2, 2 //5 = 0 and 2 % 5 = 2, we can conclude it raises the 1st stat (attack) and lowers the third (Sp Atk).
    Adamant=2,
    Bashful=12,
    Bold=5,
    Brave=4,
    Calm=15,
    Careful=17,
    Docile=6,
    Gentle=16,
    Hardy=0,
    Hasty=21,
    Impish=7,
    Jolly=22,
    Lax=8,
    Lonely=1,
    Mild=11,
    Modest=10,
    Naive=23,
    Naughty=3,
    Quiet=14,
    Quirky=18,
    Rash=13,
    Relaxed=9,
    Sassy=19,
    Serious=24,
    Timid=20
}
