// File: Command.hpp
// Author: Nee Zhong
// Date: 12/1/2025

history/CommandManager.hpp
#ifndef COMMANDMANAGER_HPP
#define COMMANDMANAGER_HPP

#include "Command.hpp"
#include <stack>
#include <memory>

class CommandManager {
public:
    CommandManager() = default;

    void doCommand(const std::shared_ptr<Command>& command);
    void undo();
    void redo();

    bool canUndo() const;
    bool canRedo() const;

private:
    std::stack<std::shared_ptr<Command>> undoStack_;
    std::stack<std::shared_ptr<Command>> redoStack_;
};

#endif // COMMANDMANAGER_HPP
