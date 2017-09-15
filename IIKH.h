#pragma once

#include <string>
#include <iostream>

using namespace std;

class IIKH{
	DBManager DB;
	string searchKeyword;

	
public:
	IIKH(FILE storedRecipes);
	IIKH();
	int readOption();	//Gives menu(browing etc.) and waits for input. returns user's input.
	
};

class Greeter{
	PlanManager pm;

public:
	PlanManager getPM();
};


class PlanManager{
	FILE storedPlans;
	Date plans[];

public:
	Date getDate();
};

class Date{
	Meal meals[5];
	string annotation;

public:
	void printAll();
	Meal getMeal(string m_name);
};

class Meal{
	Recipe items[10];
	DBManager DB;
public:
	void print();
	void insert();
	void remove();
	Recipe getRecipe();
	DBManager getDB();
};

class DBManager{
	FILE storedRecipes;
	Recipe recipeDB[128];

public:
	DBManager(FILE f);				//Instantiate DBManager.
	Recipe* findOne(string r_name);	//Find recipe that has name 'r_name', returns reference of the recipe.
	Recipe* browse(string keyword);	//Search the DB to find recipes that match the keyword what user input. It returns array of Recipe class.
	bool insert(string r_name);	//Make new recipe. Name is 'r_name', if successfully constructed Recipe, add to DB and returns true, otherwise returns false.
	bool remove(string r_name);
	bool updateFile(Recipe* list);	//Save current recipeDB to file. Returns true if everything is ok, otherwise returns false.
};

class Recipe{
	string r_name;
	int category;
	Ingredient ingredientList[20];	//
	string tags[60];	//Tags to search recipe, IIKH::browse compares this tags and its parameter 'keyword'.
	string preparationSteps[20];	//Sequencial preparation steps.
	float expTime;	//Expected preparation time.
	string reviews[100];

public:
	Recipe(string recipe_name);	//Instantiate empty instance. Only name of recipe is needed.
	void edit();		//Returns true if editing was successful, otherwise returns false.
	void display();		//Displays the recipe.
	void print();	//Request printer to print recipe.
};

class Ingredient{
	string name;
	float cost;
};