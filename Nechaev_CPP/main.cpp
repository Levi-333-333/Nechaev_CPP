#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <Windows.h>

class Creature
{
public:
	Creature(std::string name, std::list<std::string> gens)
	{
		this->name = name;
		this->gens = gens;
	}
	void AddChild(Creature* newChild)
	{
		this->children.push_back(newChild);
	}

	std::string GetName()
	{
		return name;
	}
	std::list<std::string>* GetGens()
	{
		return &gens;
	}
	std::vector<Creature*> GetChildren()
	{
		return children;
	}
	
private:
	std::string name;
	std::list<std::string> gens;
	std::vector<Creature*> children;
};

class GenTree
{
public:
	static inline unsigned int id = 0;

	void AddCreature(std::string name, std::list<std::string> gens)
	{
		registr.emplace(id, new Creature(name, gens));
		id++;
	}
	void ConnectParentWithChild(std::string parentName, std::string childName)
	{
		unsigned int parentId;
		Creature* paretn;
		Creature* child{ NULL, };

		for (auto i = registr.begin(); i != registr.end(); i++)
		{
			if (i->second->GetName() == parentName)
			{
				parentId = i->first;
				paretn = i->second;
			}
		}
		for (auto i = registr.begin(); i != registr.end(); i++)
		{
			if (i->second->GetName() == childName)
			{
				child = i->second;
			}
		}

		registr[parentId]->AddChild(child);
	}
	void PrintGetnTreeInfo()
	{
		for (auto i = registr.begin(); i != registr.end(); i++)
		{
			std::cout << "Существо " << i->first << ": " << i->second->GetName() << ". Его гены: ";
			for (auto j = i->second->GetGens()->begin(); j != i->second->GetGens()->end(); j++)
			{
				if (j == i->second->GetGens()->begin()) std::cout << *j;
				else std::cout << ", " << *j;
			}
			std::cout << ". ";
			if (i->second->GetChildren().empty()) std::cout << "У него (неё) нет детей.";
			else
			{
				std::cout << "Его (её) дети: ";
				for (int j = 0; j < i->second->GetChildren().size(); j++)
				{
					if (i->second->GetChildren()[j] == i->second->GetChildren()[0]) std::cout << i->second->GetChildren()[j]->GetName();
					else std::cout << ", " << i->second->GetChildren()[j]->GetName();
				}
			}

			std::cout << std::endl << std::endl;
		}
	}
	~GenTree()
	{
		registr.clear();
	}
private:
	std::map<unsigned int, Creature*> registr;
};

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GenTree* genTree = new GenTree();
	genTree->AddCreature("Юми", { "Лучший сапорт", "Хилочка-вардилочка" });
	genTree->AddCreature("Ниса", { "Шотландская-веслоухая", "Коричневая" });
	genTree->AddCreature("Тамья", { "Шотландская-веслоухая", "Светлая с чёрными полосками" });
	genTree->ConnectParentWithChild("Юми", "Ниса");
	genTree->ConnectParentWithChild("Юми", "Тамья");
	genTree->PrintGetnTreeInfo();
	delete genTree;

	system("pause");
	return 0;
}