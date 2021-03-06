// Copyright (c) 2017 nyorain
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

#include <vpp/fwd.hpp>
#include <vpp/resource.hpp>

namespace vpp {

/// RAII Fence wrapper
class Fence : public ResourceHandle<vk::Fence> {
public:
	Fence() = default;
	Fence(const Device&);
	Fence(const Device&, vk::Fence);
	Fence(const Device&, const vk::FenceCreateInfo&);
	~Fence();

	Fence(Fence&& lhs) noexcept { swap(lhs); }
	Fence& operator=(Fence lhs) noexcept { swap(lhs); return *this; }
};

/// RAII semaphore wrapper
class Semaphore : public ResourceHandle<vk::Semaphore> {
public:
	Semaphore() = default;
	Semaphore(const Device&);
	Semaphore(const Device&, vk::Semaphore);
	Semaphore(const Device&, const vk::SemaphoreCreateInfo&);
	~Semaphore();

	Semaphore(Semaphore&& lhs) noexcept { swap(lhs); }
	Semaphore& operator=(Semaphore lhs) noexcept { swap(lhs); return *this; }
};

/// RAII event wrapper
class Event : public ResourceHandle<vk::Event> {
public:
	Event() = default;
	Event(const Device&);
	Event(const Device&, vk::Event);
	Event(const Device&, const vk::EventCreateInfo&);
	~Event();

	Event(Event&& lhs) noexcept { swap(lhs); }
	Event& operator=(Event lhs) noexcept { swap(lhs); return *this; }
};

} // namespace vpp
