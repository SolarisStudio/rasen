#pragma once

#include <Widget.h>
#include <string>
#include <raylib.h>


class ImageView : public Widget {
  public:
    ImageView();
    ~ImageView();

    WIDGET_CONSTRUCT(ImageView);
    WIDGET_CONSTRUCT_PARENT(ImageView);

    void update(float) override;
    void draw() override;

    bool loadFromFile(const std::string &filepath);
    bool loadFromFile(const char *filepath);
    void unload();

  private:
    Texture2D m_texture;
    std::string m_filepath = "";
    bool m_is_loaded = false;
    bool m_need_loading = false;
};
