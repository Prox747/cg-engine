#pragma once

#include "core/memory.hpp"
#include "core/uuid.hpp"
#include "core/system.hpp"
#include "core/events/event.hpp"
#include "graphics/window.hpp"
#include "graphics/device.hpp"
#include "graphics/renderer.hpp"
#include "scene/scene.hpp"

#include <iostream>
#include <stdexcept>

int main();

namespace CGEngine {

    class Application {
    public:
        Application();
        virtual ~Application() {
            for (auto& [_, system] : m_systems) {
                system->onShutdown();
                delete system;
            }
        };

        static Application& get() { return *Instance; }

        void addSystem(System* system) {
            m_systems[system->getId()] = system;
            system->onInit();
        }

        void removeSystem(System* system) {
            system->onShutdown();
            m_systems.erase(system->getId());
        }

        Scene& getScene() {
            return m_scene;
        }

        Device& getDevice() {
            return m_device;
        }

        Window& getWindow() {
            return m_window;
        }
    
    private:
        void run();
        void onEvent(Event& event);
        bool isRunning();

        bool m_running = true;

        Window m_window{WindowData()};
        Device m_device{m_window};
        Renderer m_renderer{m_window, m_device};

        Scene m_scene{};

        std::unordered_map<UUID, System*> m_systems;

        static Application* Instance;

        friend int ::main();
    };

    Application* initApplication();
}