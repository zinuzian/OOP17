#pragma once

#include <string>
#include <iostream>

using namespace std;

class IIKH{
	/*
	 This class exists 
	*/
	Greeter g;

public:
	
};

class Greeter{
	/*
	 This class greets user.

	*/
	PlanManager pm;
	DBManager DB;
public:
	PlanManager getPM();	//to communicate with PlanManager
	DBManager getDB();	//to communicate with DB
	void printMenu();	//print main menu. browsing, adding/editing recipe, making/reviewing meal plan are provided.
	void browseRecipe();
	void addR();
	vpod 
};


class PlanManager{
	Date *plans;	//array of Date class to represent plan

public:
	PlanManager(string pm_filename); //load stored informations from file
	Date getDate();	//get certain Date
	void diplay();	//
};

class Date{
	Meal meals[5];
	string annotation;

public:
	void printAll();	//print whole meals for this date
	Meal getMeal(string m_name);	//to communicate with meal
};

class Meal{
	Recipe items[10];
	DBManager DB;
public:
	void print();	//print this meal's data(items)
	void insert();	//insert new recipe to this meal
	void remove();	//remove certain recipe
	Recipe getRecipe();	//to communicate with recipe
	DBManager getDB();	//to communicate with DB
};

class DBManager{
	Recipe recipeDB[128];

public:
	DBManager(string db_filename);		//Instantiate DBManager with file stored in memory.
	Recipe* findOne(string r_name);	//Find recipe that has name 'r_name', returns reference of the recipe.
	Recipe* browse(string keyword);	//Search the DB to find recipes that match the keyword what user input. It returns array of Recipe class.
	bool insert(string r_name);	//Make new recipe. Name is 'r_name', if successfully constructed Recipe, add to DB and returns true, otherwise returns false.
	bool remove(string r_name);	//remove recipe which name is r_name. returns false if remove failed.
	bool updateFile(Recipe* list);	//Save current recipeDB to file. Returns true if everything is ok, otherwise returns false.
};

class Recipe{
	string r_name;	//name of the recipe
	int category;	//recipe's category
	Ingredient ingredientList[20];	//list of ingredients needed for this recipe
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