#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Book {
public:
    string author;
    string genre;
    string rating;
    string title;
    Book(string author, string genre, string rating, string title) {
        this -> author = author;
        this -> genre = genre;
        this -> rating = rating;
        this -> title = title;
    }
    void print(Book book) {
        cout << "꘎♡ ━━━━━━━━━━━━━━━━━━━━━━━━━━ ♡꘎" << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "Rating: " << book.rating << endl << endl;
    }
};

class Map {
public:
    vector <Book> books;
    unordered_map <string, string> bookGenre;
    unordered_map <string, string> bookRating;
    Map(vector <Book> books) {
        this -> books = books;
        //initialize the maps by going through books vector
        for(int i=0; i<books.size(); i++) {
            Book toInsert = books.at(i);
            string title = toInsert.title;
            string genre = toInsert.genre;
            string rating = toInsert.rating;
            bookGenre.insert(pair<string, string> (title, genre));
            bookRating.insert(pair<string, string> (title, rating));
        }
    }
};

void qhelper (vector<pair<string, string>> temp) {
    if (temp.size() > 1) {
        vector<pair<string, string>> less, greater;
        pair<string, string> pivot = temp[0];
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].second <= pivot.second)
                less.push_back(temp[i]);
            else
                greater.push_back(temp[i]);
        }
        if (less.size() > 0)
            qhelper(less);
        if (greater.size() > 0)
            qhelper(greater);
        for (int i = 0; i < less.size(); i++)
            temp[i] = less[i];
        temp[less.size()] = pivot;
        for (int i = 0; i < greater.size(); i++)
            temp[i + less.size() + 1] = greater[i];
    }
}

void quickSortGenre(unordered_map <string, string> bookGenre) {
    unordered_map <string, string> sorted;
    vector<pair<string,string>> temp;

    for (auto& itr : bookGenre)
        temp.push_back(itr);
    qhelper(temp);
    for (auto& itr : temp)
        sorted[itr.first] = itr.second;
    cout << "Quick Sort by Genre:" << endl;
    for (auto& i : sorted)
        cout << i.first << ", " << i.second << endl;
}

void mHelperG2 (vector<pair<string, string>> temp, int start, int mid, int end) {
    vector<pair<string, string>> hold;
    int s, m;
    s = start;
    m = mid + 1;
    while (s <= mid && m <= end) {
        if (temp[s].second <= temp[m].second) {
            hold.push_back(temp[s]);
            ++s;
        }
        else {
            hold.push_back(temp[m]);
            ++m;
        }
    }
    while (s <= mid) {
        hold.push_back(temp[s]);
        ++s;
    }
    while (m <= end) {
        hold.push_back(temp[m]);
        ++m;
    }
    for (int i = start; i <= end; ++i) {
        temp[i] = hold[i-start];
    }
}

void mhelperG1 (vector<pair<string, string>> temp, int start, int end) {
    if (start < end) {
        int mid = (start + end) /2;
        mhelperG1(temp, start, mid);
        mhelperG1(temp,mid + 1, end);
        mHelperG2(temp, start, mid, end);
    }
}

void mergeSortGenre(unordered_map <string, string> bookGenre) {
    unordered_map<string, string> sorted;
    vector<pair<string, string>> temp;

    for (auto& itr : bookGenre)
        temp.push_back(itr);
    mhelperG1(temp, 0, temp.size()-1);
    for (auto& itr : temp)
        sorted[itr.first] = itr.second;
    cout << "Merge Sort by Genre:" << endl;
    for (auto& i : sorted)
        cout << i.first << ", " << i.second << endl;
}

void qhelper2 (vector<pair<string, string>> temp) {
    if (temp.size() > 1) {
        vector<pair<string, string>> less, greater;
        pair<string, string> pivot = temp[0];
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].second <= pivot.second)
                less.push_back(temp[i]);
            else
                greater.push_back(temp[i]);
        }
        if (less.size() > 0)
            qhelper2(less);
        if (greater.size() > 0)
            qhelper2(greater);
        for (int i = 0; i < less.size(); i++)
            temp[i] = less[i];
        temp[less.size()] = pivot;
        for (int i = 0; i < greater.size(); i++)
            temp[i + less.size() + 1] = greater[i];
    }
}

void quickSortRating(unordered_map <string, string> bookRating) {
    unordered_map<string, string> sorted;
    vector<pair<string, string>> temp;

    for (auto& itr : bookRating)
        temp.push_back(itr);
    qhelper2(temp);
    for (auto& itr : temp)
        sorted[itr.first] = itr.second;
    cout << "Quick Sort by Rating:" << endl;
    for (auto& i : sorted)
        cout << i.first << ", " << i.second << endl;
}

void mHelperR2 (vector<pair<string, string>> temp, int start, int mid, int end) {
    vector<pair<string, string>> hold;
    int s, m;
    s = start;
    m = mid + 1;
    while (s <= mid && m <= end) {
        if (temp[s].second <= temp[m].second) {
            hold.push_back(temp[s]);
            ++s;
        }
        else {
            hold.push_back(temp[m]);
            ++m;
        }
    }
    while (s <= mid) {
        hold.push_back(temp[s]);
        ++s;
    }
    while (m <= end) {
        hold.push_back(temp[m]);
        ++m;
    }
    for (int i = start; i <= end; ++i) {
        temp[i] = hold[i-start];
    }
}

void mhelperR1 (vector<pair<string, string>> temp, int start, int end) {
    if (start < end) {
        int mid = (start + end) /2;
        mhelperR1(temp, start, mid);
        mhelperR1(temp,mid + 1, end);
        mHelperR2(temp, start, mid, end);
    }
}

void mergeSortRating(unordered_map <string, string> bookRating) {
    unordered_map<string, string> sorted;
    vector<pair<string, string>> temp;

    for (auto& itr : bookRating)
        temp.push_back(itr);
    mhelperR1(temp, 0, temp.size()-1);
    for (auto& itr : temp)
        sorted[itr.first] = itr.second;
    cout << "Merge Sort by Rating:" << endl;
    for (auto& i : sorted)
        cout << i.first << ", " << i.second << endl;
}

int main() {
    //reference: http://www.cplusplus.com/doc/tutorial-nl/files/
    //dataset: https://www.kaggle.com/mdhamani/goodreads-books-100k

    //parses data from the .csv file to be imported into book classes
    ifstream file;
    string line;
    file.open("../GoodReads_100k_books.csv", ios::in);
    string author, genre, rating, title;
    vector <Book> books;
    if(file.is_open()) {
        while(getline(file, line)) {
            // cout << line << endl;
            istringstream stream(line);
            getline(stream, author, ',');
            getline(stream, genre, ',');
            getline(stream, rating, ',');
            getline(stream, title, ',');
            Book* a = new Book(author, genre, rating, title);
            books.push_back(*a);
        }
    }
    else {
        cout << "unable to open file";
    }
    file.close();

    Map b = Map(books);

    //reference - to calculate execution time: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

    //user interface

    //initializes clock to calculate run time in compiler
    clock_t startQuickGenre, endQuickGenre, startQuickRating, endQuickRating, startMergeGenre, endMergeGenre, startMergeRating, endMergeRating;
    bool done = false;
    while(!done) {

        //prints out option list for user
        cout << "-----------   Option 1:　　 -----------"  << endl << "Sort by rating: " << endl;
        cout << "-----------   Option 2:　　 -----------" << endl << "Sort by genre: " << endl;
        cout << "-----------   Option 3:　　 -----------" << endl << "Exit" << endl;

        int option;
        cin >> option;

        if(option == 1) {
            cout << "You chose: -----------   Sort by rating　　-----------" << endl;
            cout << "Calculating merge sort vs. quick sort" << endl;
            //calculate the time it takes
            startQuickRating = clock();
            quickSortRating(b.bookRating);
            endQuickRating = clock();
            float qrating = (endQuickRating-startQuickRating) / (float) CLOCKS_PER_SEC;
            startMergeRating = clock();
            mergeSortRating(b.bookRating);
            endQuickRating = clock();
            float mrating = (endQuickRating - startQuickRating) / (float) CLOCKS_PER_SEC;
            cout << "Quick sort time: " << qrating << " seconds" << endl;
            cout << "Merge sort time: " << mrating << " seconds" << endl;
        }
        else if (option == 2) {
            //do some action
            cout << "You chose: -----------   Sort by genre　　-----------" << endl;
            cout << "Calculating merge sort vs. quick sort" << endl;
            startQuickGenre = clock();
            quickSortGenre(b.bookGenre);
            endQuickGenre = clock();
            float qgenre = (endQuickGenre - startQuickGenre) / (float) CLOCKS_PER_SEC;

            startMergeGenre = clock();
            mergeSortGenre(b.bookGenre);
            endMergeGenre = clock();
            float mgenre = (endQuickGenre - startQuickGenre) / (float) CLOCKS_PER_SEC;
            cout << "Quick sort time: " << qgenre << " seconds" << endl;
            cout << "Merge sort time: " << mgenre << " seconds" << endl;
        }

        else if(option == 3) {
            cout << "Goodbye! Have a nice day :)" << endl;
            done = true;
            break;
        }
        else {
            cout << "Invalid option, please try again using the option list" << endl;
            cout << "-----------   Option 1:　　 -----------"  << endl << "Sort by rating: " << endl;
            cout << "-----------   Option 2:　　 -----------" << endl << "Sort by genre: " << endl;
            cout << "-----------   Option 3:　　 -----------" << endl << "Exit" << endl;
            int option;
            cin >> option;
        }
    }
}