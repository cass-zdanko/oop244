/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Pat Zdanko
Student Id: 129430195
Revision History RESUBMISSION
-----------------------------------------------------------
Date       Reason
2020/03/11 Initial Submission
2020/03/12 Resubmission - changed m_MenuItems array to 
           array of pointers
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

namespace sdds {
const int MAX_NO_OF_ITEMS = 10;
class MenuItem {
    friend class Menu;
    char* m_itemTitle;
    MenuItem();
    MenuItem(const char* itemTitle);
    MenuItem(const MenuItem& src) = delete;
    MenuItem& operator=(const MenuItem& src) = delete;
    ~MenuItem();
    void clearItemMemory();
    void setItemTitle(const char* n_itemTitle);
};
class Menu {
    char* m_title;
    MenuItem* m_MenuItems[MAX_NO_OF_ITEMS];
    int m_numOfItems; // number of items in m_menuItems
    int m_indentLevel; // 4 spaces per level
public:
    Menu();
    Menu(const char* title, int indentLevel = 0);
    Menu(const Menu& src);
    Menu& operator=(const Menu& src);
    ~Menu();
    void clearTitleMemory();
    void clearMenuItemsMemory();
    void setEmpty();
    operator bool() const;
    bool isEmpty() const;
    void display() const;
    Menu& operator=(const char* n_title);
    void add(const char* n_menuItem);
    Menu& operator<<(const char* n_menuItem);
    int run() const;
    operator int() const;
};
void indent(int numOfIndents); //helper function handling indentation
}

#endif


