#include "ImageView.h"
#include "DrawUtils.h"

ImageView::ImageView(){
  m_texture = {0};
  this->set_size(100,100);
}

ImageView::~ImageView(){
  ImageView::unload();
}

bool ImageView::loadFromFile(const std::string& filepath){
  return loadFromFile(filepath.c_str());
}

bool ImageView::loadFromFile(const char *filepath){
  m_filepath = std::string(filepath);
  m_need_loading = true;
  return true;
}

void ImageView::unload(){
  if(m_is_loaded){
    UnloadTexture(m_texture);
    m_is_loaded = false;
  }
}

void ImageView::update(float dt){
  if(m_need_loading && IsWindowReady()){
    ImageView::unload();
    m_texture = LoadTexture(m_filepath.c_str());
    if(m_texture.id != 0){
      m_is_loaded = true;
      this->set_size(m_texture.width, m_texture.height);
    }
    m_need_loading = false;
  }
}

void ImageView::draw(){
  auto rect = this->bounding_rect();
  if(m_is_loaded){
    DrawTexture(m_texture, rect.x, rect.y, WHITE);
  }else {
    DrawUtils::DrawRectangleInset(rect, 2.f, LIGHTGRAY);
    DrawTextEx(GetFontDefault(), "No Image", (Vector2){rect.x + 10, rect.y + 10}, 10, 1, DARKGRAY);
  }
}
