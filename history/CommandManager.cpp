// File: CommandManager.cpp
// Author: Nee Zhong
// Date: 12/1/2025

history/CommandManager.cpp
#include "CommandManager.hpp"

void CommandManager::doCommand(const std::shared_ptr<Command>& command) {
    command->execute();
    undoStack_.push(command);

    // Clear redo stack whenever a new command is executed
    while (!redoStack_.empty()) {
        redoStack_.pop();
    }
}

void CommandManager::undo() {
    if (!undoStack_.empty()) {
        auto command = undoStack_.top();
        undoStack_.pop();
        command->undo();
        redoStack_.push(command);
    }
}

void CommandManager::redo() {
    if (!redoStack_.empty()) {
        auto command = redoStack_.top();
        redoStack_.pop();
        command->redo();
        undoStack_.push(command);
    }
}

bool CommandManager::canUndo() const {
    return !undoStack_.empty();
}

bool CommandManager::canRedo() const {
    return !redoStack_.empty();
}