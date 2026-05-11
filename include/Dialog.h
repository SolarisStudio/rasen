#pragma once

enum class DialogIcon {
  INFO,
  WARNING,
  ERROR,
  QUESTION
};


inline const char* dialog_icon_str(DialogIcon icon) {
    if (icon == DialogIcon::INFO)
        return "info";
    if (icon == DialogIcon::WARNING)
        return "warning";
    if (icon == DialogIcon::ERROR)
        return "error";
    if (icon == DialogIcon::QUESTION)
        return "question";
    return "info";
}
