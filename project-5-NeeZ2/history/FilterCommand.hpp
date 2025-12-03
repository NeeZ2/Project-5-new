// File: FitlerCommand.hpp
// Author: Nee Zhong
// Date: 12/1/2025

history/FilterCommand.hpp
#ifndef FILTERCOMMAND_HPP
#define FILTERCOMMAND_HPP

#include "Command.hpp"
#include "../filters/ImageFilter.hpp"
#include "../files/ImageFile.hpp"
#include <memory>
#include <vector>

class FilterCommand : public Command {
public:
    /** 
     * @param imageFile The ImageFile object to be modified as a (non-const) reference
     * @param filter The filter to be applied (e.g., InvertFilter) as a const reference
     */
    FilterCommand(ImageFile& imageFile, const ImageFilter& filter);

    void execute() override;
    void undo() override;
    void redo() override;

    ImageFile& getModifiedImage() const;
    std::shared_ptr<ImageFilter> getAppliedFilter() const;
    std::string toString() const override;

private:
    ImageFile& image_;
    const std::shared_ptr<ImageFilter> applied_filter_;
    std::vector<std::vector<Pixel>> before_;
    std::vector<std::vector<Pixel>> after_;
};

#endif // FILTERCOMMAND_HPP