#pragma once

typedef struct element
{
    int ligne;
    struct element *suiv;
} element;

typedef element *Liste;