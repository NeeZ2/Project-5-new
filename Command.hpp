// File: Command.hpp
// Author: Nee Zhong
// Date: 12/1/2025

history/Command.hpp 
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
public:
    /** 
     * @brief Executes the command's primary action
     * - Saves the "previous" state before execution of the action
     * - Saves the "after" state after execution of the action
     */
    virtual void execute() = 0;

    /** 
     * @brief Undoes the action performed by execute()
     * typically by restoring the "previous" state
     */
    virtual void undo() = 0;

    /** 
     * @brief Re-applies the action performed by execute()
     * typically by restoring the "after" state
     */
    virtual void redo() = 0;

    /** 
     * @brief Returns a stringified version of the command.
     * @return A const std::string describing the command.
     */
    virtual std::string toString() const = 0;

    /** 
     * @brief Virtual destructor
     */
    virtual ~Command() = default;
};

#endif // COMMAND_HPP