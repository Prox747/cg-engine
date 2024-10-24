#include "cgengine.h"

using namespace CGEngine;

class CameraController : public Script {
    public:
        void onUpdate(float deltaTime) override;
        
    private:
        float m_moveSpeed{3.f};
        float m_lookSpeed{1.5f};
};