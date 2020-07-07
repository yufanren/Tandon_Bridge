#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

const char ANT_REP = 'o';
const char DOODLEBUG_REP = 'X';
const char GRID_REP = '-';
const int GRID_DIMENSION = 20;
const int ANT_BREED_COUNT = 3;
const int DOODLEBUG_BREED_COUNT = 8;
const int DOODLEBUG_DEATH_COUNT = 3;
const int INITIAL_ANT_COUNT = 100;
const int INITIAL_DOODLE_COUNT = 5;

class masterGrid;

class Organism {
public:
	Organism();
	Organism(int breedCounter, int x, int y, masterGrid* msterGrid);
	virtual void move();
	virtual void breed() = 0;
	virtual char displaySelf() = 0;
	virtual int getDeathCounter() = 0;
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void decrementBreedCounter();
	int getBreedCounter();
	void setBreedCounter(int counter);
	bool getDirection(int& x, int& y);
	masterGrid* getWorld();
private:
	int breedCounter;
	int positionX;
	int positionY;
	void takeMove(int x, int y);
	//"world" is a "look only" pointer, no destructor required.
	masterGrid* world;
};

class ant : public Organism {
public:
	ant();
	ant(int x, int y, masterGrid* masterGrid);
	void move();
	void breed();
	char displaySelf();
	int getDeathCounter();
};

class doodlebug : public Organism {
public:
	doodlebug();
	doodlebug(int x, int y, masterGrid* masterGrid);
	void move();
	void breed();
	char displaySelf();
	void eat(ant* ant);
	void setDeathCounter(int counter);
	int getDeathCounter();
private:
	bool findAnt(int& x, int& y);
	void starve();
	int deathCounter;
};

class masterGrid {
public:
	masterGrid();
	Organism*** getGrid();
	set<Organism*> getAnts();
	set<Organism*> getDoodleBugs();
	void addAnt(ant* ant);
	void addDoodleBug(doodlebug* doodlebug);
	void removeAnt(ant* ant);
	void removeDoodleBug(doodlebug* doodlebug);
	void modifyGrid(int x, int y, Organism* organismPtr);
	int getTurn();
	void finishTurn();
	masterGrid(const masterGrid& world1);
	~masterGrid();
	void operator =(const masterGrid& world1);
private:
	int turn;
	Organism*** grid;
	set<Organism*>* ants;
	set<Organism*>* doodlebugs;
};

Organism*** createGrid(int size);
void displayGrid(masterGrid* masterGrid);
void populateAnts(masterGrid* masterGrid);
void populateDoodles(masterGrid* masterGrid);
int* yChooseX(int y, int x);
void getRandDirection(int num, int& xOffset, int& yOffset);
bool validatePosition(int x, int y);
bool isEmpty(int x, int y, masterGrid* masterGrid);
bool isAnt(int x, int y, masterGrid* masterGrid);
void takeTurn(masterGrid* masterGrid);
masterGrid* startSimulation();

/*Class Organism*/

Organism::Organism(int breedCounter, int x, int y, masterGrid* masterGrid) :
	breedCounter(breedCounter), positionX(x), positionY(y), world(masterGrid) {}

Organism::Organism() : breedCounter(-1), positionX(-1), positionY(-1), world(nullptr) {}

int Organism::getX() { return positionX; }

int Organism::getY() { return positionY; }

void Organism::setX(int x) { positionX = x; }

void Organism::setY(int y) { positionY = y; }

masterGrid* Organism::getWorld() { return world; }

int Organism::getBreedCounter() { return breedCounter; }

void Organism::setBreedCounter(int counter) { breedCounter = counter; }

void Organism::decrementBreedCounter() {
	if (breedCounter > 0)
		breedCounter--;
}

bool Organism::getDirection(int& x, int& y) {
	int a = getX(), b = getY();
	int aOffset, bOffset;
	getRandDirection(rand() % 4, aOffset, bOffset);
	int newX = a + aOffset, newY = b + bOffset;
	if (validatePosition(newX, newY) && isEmpty(newX, newY, world)) {
		x = newX;
		y = newY;
		return true;
	}
	else
		return false;
}

void Organism::takeMove(int x, int y) {
	world->modifyGrid(x, y, this);
	world->modifyGrid(getX(), getY(), nullptr);
	setX(x);
	setY(y);
}

void Organism::move() {
	int targetX, targetY;
	if (getDirection(targetX, targetY))
		takeMove(targetX, targetY);
}

/*Class ant*/
ant::ant(int x, int y, masterGrid* masterGrid) : Organism(ANT_BREED_COUNT, x, y, masterGrid) {
	masterGrid->modifyGrid(x, y, this);
	masterGrid->addAnt(this);
}

ant::ant() : Organism() {}

int ant::getDeathCounter() { return -1; }

void ant::breed() {
	int targetX, targetY;
	if (Organism::getDirection(targetX, targetY)) 
		new ant(targetX, targetY, Organism::getWorld());
	Organism::setBreedCounter(ANT_BREED_COUNT);
}

void ant::move() {
	Organism::move();
	Organism::decrementBreedCounter();
	if (Organism::getBreedCounter() == 0)
		breed();
}

char ant::displaySelf() { return ANT_REP; }

/* Class doodlebug*/
doodlebug::doodlebug(int x, int y, masterGrid* masterGrid) :
	Organism(DOODLEBUG_BREED_COUNT, x, y, masterGrid), deathCounter(DOODLEBUG_DEATH_COUNT) {
	masterGrid->modifyGrid(x, y, this);
	masterGrid->addDoodleBug(this);
}

doodlebug::doodlebug() : Organism(), deathCounter(0) {}

void doodlebug::setDeathCounter(int counter) { deathCounter = counter; }

void doodlebug::breed() {
	int targetX, targetY;
	if (Organism::getDirection(targetX, targetY)) 
		new doodlebug(targetX, targetY, Organism::getWorld());
	Organism::setBreedCounter(DOODLEBUG_BREED_COUNT);
}

char doodlebug::displaySelf() { return DOODLEBUG_REP; }

int doodlebug::getDeathCounter() { return deathCounter; }

void doodlebug::move() {
	int targetX, targetY;
	if (findAnt(targetX, targetY))
		eat((ant*)Organism::getWorld()->getGrid()[targetY][targetX]);
	else {
		Organism::move();
		deathCounter--;
	}
	Organism::decrementBreedCounter();
	if (deathCounter == 0) {
		starve();
		return;
	}
	if (Organism::getBreedCounter() == 0)
		breed();
}

bool doodlebug::findAnt(int& x, int& y) {
	int* checkOrder = yChooseX(4, 4);
	int a = Organism::getX(), b = Organism::getY();
	int aOffset, bOffset;
	for (int i = 0; i < 4; i++) {
		getRandDirection(checkOrder[i], aOffset, bOffset);
		int newX = a + aOffset, newY = b + bOffset;
		if (validatePosition(newX, newY) && isAnt(newX, newY, Organism::getWorld())) {
			x = newX;
			y = newY;
			delete[] checkOrder;
			return true;
		}
	}
	delete[] checkOrder;
	return false;
}

void doodlebug::eat(ant* ant) {
	int targetX = ant->Organism::getX();
	int targetY = ant->Organism::getY();
	masterGrid* world = Organism::getWorld();
	world->modifyGrid(targetX, targetY, this);
	world->modifyGrid(Organism::getX(), Organism::getY(), nullptr);
	world->removeAnt(ant);
	Organism::setX(targetX);
	Organism::setY(targetY);
	delete ant;
	deathCounter = DOODLEBUG_DEATH_COUNT;
}

void doodlebug::starve() {
	Organism::getWorld()->modifyGrid(Organism::getX(), Organism::getY(), nullptr);
	Organism::getWorld()->removeDoodleBug(this);
	delete this;
}

/*Class masterGrid*/
masterGrid::masterGrid() : grid(createGrid(GRID_DIMENSION)),
ants(new set<Organism*>), doodlebugs(new set<Organism*>), turn(0) {}

void masterGrid::modifyGrid(int x, int y, Organism* organismPtr) { grid[y][x] = organismPtr; }

void masterGrid::removeDoodleBug(doodlebug* doodlebug) { doodlebugs->erase(doodlebug); }

void masterGrid::removeAnt(ant* ant) { ants->erase(ant); }

void masterGrid::addDoodleBug(doodlebug* doodlebug) { doodlebugs->insert(doodlebug); }

void masterGrid::addAnt(ant* ant) { ants->insert(ant); }

set<Organism*> masterGrid::getDoodleBugs() { return *doodlebugs; }

set<Organism*> masterGrid::getAnts() { return *ants; }

Organism*** masterGrid::getGrid() { return grid; }

int masterGrid::getTurn() { return turn; }

void masterGrid::finishTurn() { turn++; }

masterGrid::masterGrid(const masterGrid& world1) : grid(createGrid(GRID_DIMENSION)),
ants(new set<Organism*>), doodlebugs(new set<Organism*>), turn(world1.turn) {
	for (auto i : *world1.ants) {
		ant* ant1 = new ant(i->getX(), i->getY(), this);
		ant1->Organism::setBreedCounter(i->getBreedCounter());
	}
	for (auto j : *world1.doodlebugs) {
		doodlebug* doodle1 = new doodlebug(j->getX(), j->getY(), this);
		doodle1->Organism::setBreedCounter(j->getBreedCounter());
		doodle1->setDeathCounter(j->getDeathCounter());
	}
}

masterGrid::~masterGrid() {
	for (auto i : *ants)
		delete i;
	for (auto j : *doodlebugs)
		delete j;
	for (int k = 0; k < GRID_DIMENSION; k++)
		delete grid[k];
	delete grid;
	delete ants;
	delete doodlebugs;
}

void masterGrid::operator=(const masterGrid& world1) {
	if (this == &world1)
		return;
	for (auto i : *ants)
		delete i;
	for (auto j : *doodlebugs)
		delete j;
	for (int k = 0; k < GRID_DIMENSION; k++)
		delete grid[k];
	delete grid;
	delete ants;
	delete doodlebugs;
	grid = createGrid(GRID_DIMENSION);
	ants = new set<Organism*>;
	doodlebugs = new set<Organism*>;
	for (auto i : *world1.ants) {
		ant* ant1 = new ant(i->getX(), i->getY(), this);
		ant1->Organism::setBreedCounter(i->getBreedCounter());
	}
	for (auto j : *world1.doodlebugs) {
		doodlebug* doodle1 = new doodlebug(j->getX(), j->getY(), this);
		doodle1->Organism::setBreedCounter(j->getBreedCounter());
		doodle1->setDeathCounter(j->getDeathCounter());
	}
}

/*From here on are non-class functions*/
masterGrid* startSimulation() {
	masterGrid* sim1 = new masterGrid();
	populateAnts(sim1);
	populateDoodles(sim1);
	displayGrid(sim1);
	return sim1;
}

bool isAnt(int x, int y, masterGrid* masterGrid) {
	set<Organism*> ants = masterGrid->getAnts();
	return ants.find((masterGrid->getGrid())[y][x]) != ants.end();
}

bool isEmpty(int x, int y, masterGrid* masterGrid) {
	Organism*** grid = masterGrid->getGrid();
	return grid[y][x] == nullptr;
}

bool validatePosition(int x, int y) {
	return x >= 0 && x < GRID_DIMENSION && y >= 0 && y < GRID_DIMENSION;
}

void getRandDirection(int num, int& xOffset, int& yOffset) {
	switch (num) {
	case 0:
		xOffset = 0;
		yOffset = 1;
		break;
	case 1:
		xOffset = 0;
		yOffset = -1;
		break;
	case 2:
		xOffset = -1;
		yOffset = 0;
		break;
	case 3:
		xOffset = 1;
		yOffset = 0;
		break;
	}
}


void populateDoodles(masterGrid* masterGrid) {
	int doodleToSpawn = INITIAL_DOODLE_COUNT;
	while (doodleToSpawn > 0) {
		int* xyCoordinates = yChooseX(GRID_DIMENSION, 2);
		if (masterGrid->getGrid()[xyCoordinates[1]][xyCoordinates[0]] == nullptr) {
			new doodlebug(xyCoordinates[0], xyCoordinates[1], masterGrid);
			doodleToSpawn--;
		}
		delete[] xyCoordinates;
	}
}

void populateAnts(masterGrid* masterGrid) {
	int antPerRow = INITIAL_ANT_COUNT / GRID_DIMENSION;
	int antRemain = INITIAL_ANT_COUNT % GRID_DIMENSION;
	for (int i = 0; i < GRID_DIMENSION; i++) {
		int antNum = antPerRow;
		if (i < antRemain)
			antNum++;
		int* locations = yChooseX(GRID_DIMENSION, antNum);
		for (int j = 0; j < antNum; j++) {
			new ant(locations[j], i, masterGrid);
		}
		delete[] locations;
	}
}

/*produce a dynamic array, contains x random non-repeat numbers
	from 0 to y - 1, the array must be deleted after use.*/
int* yChooseX(int y, int x) {
	int* arr = new int[y];
	for (int i = 0; i < y; i++)
		arr[i] = i;
	int* randLocation = new int[x];
	int counterEnd = y - 1, counterLocation = 0;
	while (counterLocation < x) {
		int ptr = rand() % (counterEnd + 1);
		randLocation[counterLocation] = arr[ptr];
		counterLocation++;
		arr[ptr] = arr[counterEnd];
		counterEnd--;
	}
	delete[] arr;
	return randLocation;
}

Organism*** createGrid(int size) {
	Organism*** grid = new Organism * *[size];
	for (int i = 0; i < size; i++) {
		grid[i] = new Organism * [size];
		for (int j = 0; j < size; j++)
			grid[i][j] = nullptr;
	}
	return grid;
}

void displayGrid(masterGrid* masterGrid) {
	Organism*** grid = masterGrid->getGrid();
	for (int i = 0; i < GRID_DIMENSION; i++) {
		for (int j = 0; j < GRID_DIMENSION; j++) {
			if (grid[i][j] == nullptr)
				cout << GRID_REP << " ";
			else
				cout << (*grid[i][j]).displaySelf() << " ";
		}
		cout << endl;
	}
	cout << "ANTS: " << masterGrid->getAnts().size() << "    DOODLEBUGS: "
		<< masterGrid->getDoodleBugs().size() << "    TURN: " << masterGrid->getTurn() << endl;
}

void takeTurn(masterGrid* masterGrid) {
	set<Organism*> doodz = masterGrid->getDoodleBugs();
	for (auto i : doodz)
		i->move();
	set<Organism*> antz = masterGrid->getAnts();
	for (auto j : antz)
		j->move();
	masterGrid->finishTurn();
	displayGrid(masterGrid);
}

int main1(masterGrid* masterGrid) {
	char next;
	while (true) {
		cout << "Press ENTER key to go to the next turn, enter q to exit.\n";
		next = getchar();
		if (next == 'q')
			return 0;
		takeTurn(masterGrid);
	}
}

int main2(masterGrid* masterGrid) {
	int num;
	cout << "Enter number of turns for the simulation to run:\n";
	cin >> num;
	for (int i = 0; i < num; i++)
		takeTurn(masterGrid);

	return 0;
}


int main() {
	srand((unsigned int)time(NULL));
	masterGrid* test1 = startSimulation();
	masterGrid test2 = *test1;

	//Main function 1, press ENTER key to take a turn.
	main1(&test2);

	//Main function 2, perform simulation for N turns.
	//main2(&test2);	
	return 0;
}

