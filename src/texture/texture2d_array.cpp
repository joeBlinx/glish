//
// Created by stiven_perso on 11/07/2021.
//
#include "texture/texture2d_array.hpp"
#include <stb_image.h>
#include <thread>
#include <vector>
#include <algorithm>

glish3::texture2d_array::settings glish3::texture2d_array::read_images(std::span<std::string_view> image_paths) {
    int width, height, comp;
    stbi_info(image_paths[0].data(), &width, &height, &comp);
    auto constexpr number_channels = 4;// 4 channels r, g, b, a
    int const image_size = width*height*number_channels;
    auto* data = new std::byte[image_size*std::size(image_paths)];
    auto read_image = [](std::byte* data, std::string_view path, int offset){
        int width, height, comp;
        auto* data_image = stbi_load(path.data(), &width, &height, &comp, 4);
        std::memcpy(data+offset, data_image, width*height*4);
        stbi_image_free(data_image);
    };
    int offset = 0;
    std::ranges::for_each(image_paths, [&](auto const& path){
        read_image(data, path, offset);
        offset += image_size;
    });

    return {width, height, static_cast<int>(std::size(image_paths)), std::unique_ptr<std::byte>(data)};
}

glish3::texture2d_array::texture2d_array(const glish3::texture2d_array::settings &settings){
    glTextureStorage3D(_texture_unit, 1,
                       GL_RGBA8,
                       settings.width,
                       settings.height,
                       settings.number_images);

    for(int index = 0; index < settings.number_images; index++ ){

        int const offset = index*settings.width*settings.height*4;
        glTextureSubImage3D(
                _texture_unit, 0, 0, 0, index,
                settings.width, settings.height, 1,
                GL_RGBA, GL_UNSIGNED_BYTE, settings.data.get() + offset
                );
    }
}

void glish3::texture2d_array::bind(int binding_point) const {
    glBindTextureUnit(binding_point, _texture_unit);
}
