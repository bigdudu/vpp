#include <vpp/vk.hpp>
#include <vpp/device.hpp>

const vpp::Device& device();

auto fence = vk::createFence(device(), {});
std::vector<vk::BindSparseInfo> infos;

//binding a sparse buffer to a single memory object
vk::SparseMemoryBind bind;
bind.resourceOffset = 0;
bind.size = memReqs.size; //the size must be at least memReqs.alignment
bind.memory = memory;
bind.flags = {};

vk::SparseBufferMemoryBindInfo bufferBind;
bufferBind.buffer = buffer;
bufferBind.bindCount = 1;
bufferBind.pBinds = &bind;

infos.emplace_back();
infos.back().bufferBindCount = 1;
infos.back().pBufferBinds = &bufferBind;

//binding an image
//difference between opaque and partially resident images
//sparse image binding is way more complex since one has to care about metadata bindings,
//differentiate between opaque or normal bindings and query/deal with additional requirements
//and device features since some stuff might not be enabled
auto reqs = vk::getImageSparseMemoryRequirements(device(), image);

vk::SparseMemoryBind bind;
bind.resourceOffset = 0;
bind.size = memReqs.size;
bind.memory = memory;
bind.flags = {};


//submitting the sparse binding operations to the device
queue.mutex().lock();
vk::queueBindSparse(queue, infos, fence);
queue.mutex().unlock();

//wait for the fence