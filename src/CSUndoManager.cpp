//
//  CSUndoManager.cpp
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

#include "CSUndoManager.hpp"

#ifndef CSNSUndoManager

void CSUndoManager::registerUndoFunc(std::function<void()> f) {
    if (isUndoing) {
        redoStack = new UndoItem(f, redoStack);
    } else {
        undoStack = new UndoItem(f, undoStack);
        if (!this->isRedoing) {
            delete redoStack;
            redoStack = nullptr;
        }
    }
}

bool CSUndoManager::canUndo() {
    return undoStack != nullptr;
}

void CSUndoManager::undo() {
    if (undoStack != nullptr) {
        isUndoing = true;
        undoStack->f();
        isUndoing = false;
        undoStack = undoStack->next;
    }
}

bool CSUndoManager::canRedo() {
    return redoStack != nullptr;
}

void CSUndoManager::redo() {
    if (redoStack != nullptr) {
        isRedoing = true;
        redoStack->f();
        isRedoing = false;
        redoStack = redoStack->next;
    }
}

// UNTESTED
CSMenuItem* CSUndoManager::undoMenuItem(CSKeyCode keyCode) {
    return new CSMenuItem("Undo", std::bind(&CSUndoManager::undo, this), keyCode);
}

// UNTESTED
CSMenuItem* CSUndoManager::redoMenuItem(CSKeyCode keyCode) {
    return new CSMenuItem("Redo", std::bind(&CSUndoManager::redo, this), keyCode);
}

#endif
