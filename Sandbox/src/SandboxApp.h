#pragma once
#include <Mistiq/Application.h>

class SandboxApp : public Mistiq::Application {
public:
    void Setup(std::shared_ptr<Mistiq::Application> a_Self) override;
    void Update() override;
    void Clean() override;

private:
	std::vector<Mistiq::Entity> m_Player;
};