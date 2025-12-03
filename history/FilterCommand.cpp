// File: FitlerCommand.cpp
// Author: Nee Zhong
// Date: 12/1/2025

history/FilterCommand.cpp
#include "FilterCommand.hpp"

FilterCommand::FilterCommand(ImageFile& imageFile, const ImageFilter& filter)
    : image_(imageFile),
      applied_filter_(filter.clone())
{
}

void FilterCommand::execute() {
    before_ = image_.getPixels();
    applied_filter_->apply(image_);
    after_ = image_.getPixels();
}

void FilterCommand::undo() {
    image_.setPixels(before_);
}

void FilterCommand::redo() {
    image_.setPixels(after_);
}

ImageFile& FilterCommand::getModifiedImage() const {
    return image_;
}

std::shared_ptr<ImageFilter> FilterCommand::getAppliedFilter() const {
    return applied_filter_;
}

std::string FilterCommand::toString() const {
    return applied_filter_->getName() + " --> " + image_.getFilename();
}
