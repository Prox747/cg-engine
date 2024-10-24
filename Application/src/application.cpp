#include "cgengine.h"

#include "camera_controller.hpp"

#include <iostream>

using namespace CGEngine;

class App : public Application {
public:
    App() : Application() {
        loadScene();
    }

    ~App() {

    }

    void loadScene() {
        Entity camera = getScene().createEntity("camera")
            .add<TransformComponent>(glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{0.0f, 0.0f, 0.0f})
            .add<CameraComponent>();
        
        camera.addAndGet<ScriptComponent>().bind<CameraController>();

        Shared<Model> model_smooth_vase = Model::createModelFromFile(getDevice(), "../assets/models/smooth_vase.obj");
        Entity entity = getScene().createEntity("smooth_vase")
            .add<TransformComponent>(glm::vec3{-0.2f, 0.1f, 0.5f}, glm::vec3{0.5f, 0.25f, .5f}, glm::vec3{0.0f, 0.0f, 0.0f})
            .add<ColorComponent>(glm::vec3{0.6f, 0.0f, 0.5f})
            .add<ModelComponent>(model_smooth_vase);

        Shared<Model> model_bunny = Model::createModelFromFile(getDevice(), "../assets/models/stanford_bunny.obj");
        entity = getScene().createEntity("bunny")
            .add<TransformComponent>(glm::vec3{0.0f, 0.1f, 0.5f}, glm::vec3{0.5f, 0.5f, .5f}, glm::vec3{0.0f, glm::pi<float>(), 0.0f})
            .add<ColorComponent>(glm::vec3{0.6f, 0.0f, 0.5f})
            .add<ModelComponent>(model_bunny);

        Shared<Model> model_flat_vase = Model::createModelFromFile(getDevice(), "../assets/models/flat_vase.obj");
        entity = getScene().createEntity("flat_vase")
            .add<TransformComponent>(glm::vec3{0.2f, 0.1f, 0.5f}, glm::vec3{0.5f, 0.25f, .5f}, glm::vec3{0.0f, 0.0f, 0.0f})
            .add<ColorComponent>(glm::vec3{0.6f, 0.0f, 0.5f})
            .add<ModelComponent>(model_flat_vase);
    }
};

CGEngine::Application* CGEngine::initApplication() {
    return new App();
}