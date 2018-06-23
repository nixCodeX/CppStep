//
//  CSTableViewDataSource.hpp
//  CppStep
//
//  Copyright � 2018 Jonathan Tanner. All rights reserved.
//
//This file is part of CppStep.
//
//CppStep is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//CppStep is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with CppStep.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CSTableViewDataSource_hpp
#define CSTableViewDataSource_hpp

#include <string>
#include <utility>

/** A data source for a CSTableView */
class CSTableViewDataSource {
public:
    /** Get the number of rows in the table */
    virtual int numberOfRows() = 0;
    /** Get the number of columns in the table */
    virtual int numberOfColumns() = 0;
    /** Get the name of the given column
      * @param index The index of the column
      */
    virtual std::string getColumnName(int index) = 0;
    /** Get whether the given column is read only
      * @param col The name of the column
      */
    virtual bool isReadOnly(std::string col) { return true; }
    /** Get the value in a given cell
      * @return The string value in the cell
      * @param col The name of the column
      * @param row The index of the row
      */
    virtual std::string getStringValueInCell(std::string col, int row) = 0;
    /** Set the value in a given cell
      * @param col   The name of the column
      * @param row   The index of the row
      * @param value The new value to put in the cell
      */
    virtual void setStringValueInCell(std::string col, int row, std::string value) {}
};

#endif /* CSTableViewDataSource_hpp */
