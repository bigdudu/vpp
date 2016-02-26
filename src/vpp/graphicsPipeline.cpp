#include <vpp/graphicsPipeline.hpp>
#include <vpp/context.hpp>
#include <vpp/call.hpp>
#include <vpp/shader.hpp>

namespace vpp
{

unsigned int formatSize(vk::Format format)
{
	using namespace vk;

	switch(format)
    {
    case Format::Undefined: return 0;
	case Format::R4G4UnormPack8: return 8;
	case Format::R4G4B4A4UnormPack16: return 16;
    case Format::B4G4R4A4UnormPack16: return 16;
    case Format::R5G6B5UnormPack16: return 16;
    case Format::B5G6R5UnormPack16: return 16;
    case Format::R5G5B5A1UnormPack16: return 16;
    case Format::B5G5R5A1UnormPack16: return 16;
    case Format::A1R5G5B5UnormPack16: return 16;
	case Format::R8Unorm: return 8;
    case Format::R8Snorm: return 8;
    case Format::R8Uscaled: return 8;
    case Format::R8Sscaled: return 8;
    case Format::R8Uint: return 8;
    case Format::R8Sint: return 8;
    case Format::R8Srgb: return 8;
	case Format::R8G8Unorm: return 16;
    case Format::R8G8Snorm: return 16;
    case Format::R8G8Uscaled: return 16;
    case Format::R8G8Sscaled: return 16;
    case Format::R8G8Uint: return 16;
    case Format::R8G8Sint: return 16;
    case Format::R8G8Srgb: return 16;
	case Format::R8G8B8Unorm: return 24;
    case Format::R8G8B8Snorm: return 24;
    case Format::R8G8B8Uscaled: return 24;
    case Format::R8G8B8Sscaled: return 24;
    case Format::R8G8B8Uint: return 24;
    case Format::R8G8B8Sint: return 24;
    case Format::R8G8B8Srgb: return 24;
    case Format::B8G8R8Unorm: return 24;
    case Format::B8G8R8Snorm: return 24;
    case Format::B8G8R8Uscaled: return 24;
	case Format::B8G8R8Sscaled: return 24;
    case Format::B8G8R8Uint: return 24;
    case Format::B8G8R8Sint: return 24;
    case Format::B8G8R8Srgb: return 24;
	case Format::R8G8B8A8Unorm: return 32;
    case Format::R8G8B8A8Snorm: return 32;
    case Format::R8G8B8A8Uscaled: return 32;
    case Format::R8G8B8A8Sscaled: return 32;
	case Format::R8G8B8A8Uint: return 32;
    case Format::R8G8B8A8Sint: return 32;
    case Format::R8G8B8A8Srgb: return 32;
    case Format::B8G8R8A8Unorm: return 32;
    case Format::B8G8R8A8Snorm: return 32;
    case Format::B8G8R8A8Uscaled: return 32;
    case Format::B8G8R8A8Sscaled: return 32;
    case Format::B8G8R8A8Uint: return 32;
    case Format::B8G8R8A8Sint: return 32;
    case Format::B8G8R8A8Srgb: return 32;
    case Format::A8B8G8R8UnormPack32: return 32;
    case Format::A8B8G8R8SnormPack32: return 32;
    case Format::A8B8G8R8UscaledPack32: return 32;
    case Format::A8B8G8R8SscaledPack32: return 32;
    case Format::A8B8G8R8UintPack32: return 32;
    case Format::A8B8G8R8SintPack32: return 32;
    case Format::A8B8G8R8SrgbPack32: return 32;
    case Format::A2R10G10B10UnormPack32: return 32;
    case Format::A2R10G10B10SnormPack32: return 32;
    case Format::A2R10G10B10UscaledPack32: return 32;
    case Format::A2R10G10B10SscaledPack32: return 32;
    case Format::A2R10G10B10UintPack32: return 32;
    case Format::A2R10G10B10SintPack32: return 32;
    case Format::A2B10G10R10UnormPack32: return 32;
    case Format::A2B10G10R10SnormPack32: return 32;
    case Format::A2B10G10R10UscaledPack32: return 32;
    case Format::A2B10G10R10SscaledPack32: return 32;
    case Format::A2B10G10R10UintPack32: return 32;
    case Format::A2B10G10R10SintPack32: return 32;
    case Format::R16Unorm: return 16;
    case Format::R16Snorm: return 16;
    case Format::R16Uscaled: return 16;
    case Format::R16Sscaled: return 16;
	case Format::R16Uint: return 16;
    case Format::R16Sint: return 16;
    case Format::R16Sfloat: return 16;
    case Format::R16G16Unorm: return 32;
    case Format::R16G16Snorm: return 32;
    case Format::R16G16Uscaled: return 32;
    case Format::R16G16Sscaled: return 32;
    case Format::R16G16Uint: return 32;
    case Format::R16G16Sint: return 32;
    case Format::R16G16Sfloat: return 32;
	case Format::R16G16B16Unorm: return 48;
    case Format::R16G16B16Snorm: return 48;
    case Format::R16G16B16Uscaled: return 48;
    case Format::R16G16B16Sscaled: return 48;
    case Format::R16G16B16Uint: return 48;
    case Format::R16G16B16Sint: return 48;
    case Format::R16G16B16Sfloat: return 48;
	case Format::R16G16B16A16Unorm: return 64;
    case Format::R16G16B16A16Snorm: return 64;
    case Format::R16G16B16A16Uscaled: return 64;
    case Format::R16G16B16A16Sscaled: return 64;
    case Format::R16G16B16A16Uint: return 64;
    case Format::R16G16B16A16Sint: return 64;
    case Format::R16G16B16A16Sfloat: return 64;
	case Format::R32Uint: return 32;
    case Format::R32Sint: return 32;
    case Format::R32Sfloat: return 32;
    case Format::R32G32Uint: return 64;
    case Format::R32G32Sint: return 64;
    case Format::R32G32Sfloat: return 64;
	case Format::R32G32B32Uint: return 96;
    case Format::R32G32B32Sint: return 96;
    case Format::R32G32B32Sfloat: return 96;
	case Format::R32G32B32A32Uint: return 128;
    case Format::R32G32B32A32Sint: return 128;
    case Format::R32G32B32A32Sfloat: return 128;
    case Format::R64Uint: return 64;
    case Format::R64Sint: return 64;
    case Format::R64Sfloat: return 64;
    case Format::R64G64Uint: return 128;
    case Format::R64G64Sint: return 128;
    case Format::R64G64Sfloat: return 128;
	case Format::R64G64B64Uint: return 192;
    case Format::R64G64B64Sint: return 192;
	case Format::R64G64B64Sfloat: return 192;
    case Format::R64G64B64A64Uint: return 256;
    case Format::R64G64B64A64Sint: return 256;
    case Format::R64G64B64A64Sfloat: return 256;
	case Format::B10G11R11UfloatPack32: return 32;
    case Format::E5B9G9R9UfloatPack32: return 32;
	case Format::D16Unorm: return 16;
    case Format::X8D24UnormPack32: return 32;
    case Format::D32Sfloat: return 32;
	case Format::S8Uint: return 8;
	case Format::D16UnormS8Uint: return 24;
    case Format::D24UnormS8Uint: return 48;
	/*
    case Format::D32SfloatS8Uint: return "32SfloatS8Uint";
    case Format::Bc1RgbUnormBlock: return "c1RgbUnormBlock";
    case Format::Bc1RgbSrgbBlock: return "c1RgbSrgbBlock";
    case Format::Bc1RgbaUnormBlock: return "c1RgbaUnormBlock";
    case Format::Bc1RgbaSrgbBlock: return "c1RgbaSrgbBlock";
    case Format::Bc2UnormBlock: return "c2UnormBlock";
    case Format::Bc2SrgbBlock: return "c2SrgbBlock";
    case Format::Bc3UnormBlock: return "c3UnormBlock";
    case Format::Bc3SrgbBlock: return "c3SrgbBlock";
    case Format::Bc4UnormBlock: return "c4UnormBlock";
    case Format::Bc4SnormBlock: return "c4SnormBlock";
    case Format::Bc5UnormBlock: return "c5UnormBlock";
    case Format::Bc5SnormBlock: return "c5SnormBlock";
    case Format::Bc6HUfloatBlock: return "c6HUfloatBlock";
    case Format::Bc6HSfloatBlock: return "c6HSfloatBlock";
    case Format::Bc7UnormBlock: return "c7UnormBlock";
    case Format::Bc7SrgbBlock: return "c7SrgbBlock";
    case Format::Etc2R8G8B8UnormBlock: return "tc2R8G8B8UnormBlock";
    case Format::Etc2R8G8B8SrgbBlock: return "tc2R8G8B8SrgbBlock";
    case Format::Etc2R8G8B8A1UnormBlock: return "tc2R8G8B8A1UnormBlock";
    case Format::Etc2R8G8B8A1SrgbBlock: return "tc2R8G8B8A1SrgbBlock";
    case Format::Etc2R8G8B8A8UnormBlock: return "tc2R8G8B8A8UnormBlock";
    case Format::Etc2R8G8B8A8SrgbBlock: return "tc2R8G8B8A8SrgbBlock";
    case Format::EacR11UnormBlock: return "acR11UnormBlock";
    case Format::EacR11SnormBlock: return "acR11SnormBlock";
    case Format::EacR11G11UnormBlock: return "acR11G11UnormBlock";
    case Format::EacR11G11SnormBlock: return "acR11G11SnormBlock";
    case Format::Astc4x4UnormBlock: return "stc4x4UnormBlock";
    case Format::Astc4x4SrgbBlock: return "stc4x4SrgbBlock";
    case Format::Astc5x4UnormBlock: return "stc5x4UnormBlock";
    case Format::Astc5x4SrgbBlock: return "stc5x4SrgbBlock";
    case Format::Astc5x5UnormBlock: return "stc5x5UnormBlock";
    case Format::Astc5x5SrgbBlock: return "stc5x5SrgbBlock";
    case Format::Astc6x5UnormBlock: return "stc6x5UnormBlock";
    case Format::Astc6x5SrgbBlock: return "stc6x5SrgbBlock";
    case Format::Astc6x6UnormBlock: return "stc6x6UnormBlock";
    case Format::Astc6x6SrgbBlock: return "stc6x6SrgbBlock";
    case Format::Astc8x5UnormBlock: return "stc8x5UnormBlock";
    case Format::Astc8x5SrgbBlock: return "stc8x5SrgbBlock";
    case Format::Astc8x6UnormBlock: return "stc8x6UnormBlock";
    case Format::Astc8x6SrgbBlock: return "stc8x6SrgbBlock";
    case Format::Astc8x8UnormBlock: return "stc8x8UnormBlock";
    case Format::Astc8x8SrgbBlock: return "stc8x8SrgbBlock";
    case Format::Astc10x5UnormBlock: return "stc10x5UnormBlock";
    case Format::Astc10x5SrgbBlock: return "stc10x5SrgbBlock";
    case Format::Astc10x6UnormBlock: return "stc10x6UnormBlock";
    case Format::Astc10x6SrgbBlock: return "stc10x6SrgbBlock";
    case Format::Astc10x8UnormBlock: return "stc10x8UnormBlock";
    case Format::Astc10x8SrgbBlock: return "stc10x8SrgbBlock";
    case Format::Astc10x10UnormBlock: return "stc10x10UnormBlock";
    case Format::Astc10x10SrgbBlock: return "stc10x10SrgbBlock";
    case Format::Astc12x10UnormBlock: return "stc12x10UnormBlock";
    case Format::Astc12x10SrgbBlock: return "stc12x10SrgbBlock";
    case Format::Astc12x12UnormBlock: return "stc12x12UnormBlock";
    case Format::Astc12x12SrgbBlock: return "stc12x12SrgbBlock";
	*/
	default: return 0;
	}
}

unsigned int bindID = 0;

GraphicsPipeline::GraphicsPipeline(const Device& device, vk::RenderPass renderPass)
{
	create(device, renderPass);

}

GraphicsPipeline::~GraphicsPipeline()
{
	destroy();
}

void GraphicsPipeline::create(const Device& device, const CreateInfo& createInfo)
{
	destroy();
	Resource::create(device);

	//vertexInfo
	vk::PipelineVertexInputStateCreateInfo vertexInfo;

	//Binding description
	std::size_t attributeCount = 0;
	for(auto& layout : createInfo.vertexBufferLayouts)
		attributeCount += layout.attributes.size();

	std::vector<vk::VertexInputBindingDescription> bindingDescriptions;
	bindingDescriptions.reserve(createInfo.vertexBufferLayouts.size());

	std::vector<vk::VertexInputAttributeDescription> attributeDescriptions;
	attributeDescriptions.reserve(attributeCount);

	for(auto& layout : createInfo.vertexBufferLayouts)
	{
		std::size_t location = 0;
		std::size_t offset = 0;
		for(auto& attribute : layout.attributes)
		{
			attributeDescriptions.emplace_back();
			attributeDescriptions.back().location(location++);
			attributeDescriptions.back().binding(layout.binding);
			attributeDescriptions.back().format(attribute);
			attributeDescriptions.back().offset(offset);
			offset += formatSize(attribute);
		}

		bindingDescriptions.push_back();
		bindingDescriptions.back().binding(layout.binding);
		bindingDescriptions.back().stride(offset);
		bindingDescriptions.back().inputRate(vk::VertexInputRate::Vertex);
	}

	vertexInfo.vertexBindingDescriptionCount(bindingDescriptions.size());
	vertexInfo.pVertexBindingDescriptions(bindingDescriptions.data());
	vertexInfo.vertexAttributeDescriptionCount(attributeDescriptions.size());
	vertexInfo.pVertexAttributeDescriptions(attributeDescriptions.data());

	//pipeline layout
	std::vector<vk::DescriptorSetLayout> descriptorSetLayouts;
	descriptorSetLayouts.reserve(createInfo.descriptorSetLayouts.size());

	for(auto& layout : createInfo.descriptorSetLayouts)
		descriptorSetLayouts.push_back(layout.vkDescriptorSetLayout());

	vk::PipelineLayoutCreateInfo pipelineLayoutInfo;
	pipelineLayoutInfo.setLayoutCount(descriptorSetLayouts.size());
	pipelineLayoutInfo.pSetLayouts(descriptorSetLayouts.data());

	vk::createPipelineLayout(vkDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout_);

	//dynamic state
	vk::PipelineDynamicStateCreateInfo dynamicState;
	dynamicState.pDynamicStates(createInfo.dynamicState.data());
	dynamicState.dynamicStateCount(createInfo.dynamicState.size());

	//create it
	vk::GraphicsPipelineCreateInfo pipelineInfo;

	pipelineInfo.layout(pipelineLayout);
	pipelineInfo.pVertexInputState(&vertexInfo);
	pipelineInfo.pDynamicState(&dynamicState);
	pipelineInfo.renderPass(createInfo.renderPass);
	pipelineInfo.stageCount(createInfo.shaderProgram.stages().size());
	pipelineInfo.pStages(createInfo.shaderProgram.stages().data());s
	pipelineInfo.pInputAssemblyState(&createInfo.inputAssemblyState);
	pipelineInfo.pRasterizationState(&createInfo.rasterizationState);
	pipelineInfo.pColorBlendState(&createInfo.colorBlendState);
	pipelineInfo.pMultisampleState(&createInfo.multisampleState);
	pipelineInfo.pViewportState(&createInfo.viewportState);
	pipelineInfo.pDepthStencilState(&createInfo.depthStencilState);

	vk::createGraphicsPipelines(vkDevice(), 0, 1, &pipelineInfo, nullptr, &pipeline_);
}

void GraphicsPipeline::destroy()
{

}

void GraphicsPipeline::renderCommands(vk::CommandBuffer cmdBuffer) const
{
	vk::DeviceSize offsets[1] = { 0 };

/*
	vk::cmdBindDescriptorSets(cmdBuffer, vk::PipelineBindPoint::Graphics, pilelineLayout_,
		0, 1, &descriptorSet_, 0, nullptr);
*/

	vk::cmdBindPipeline(cmdBuffer, vk::PipelineBindPoint::Graphics, pipeline_);
	vk::cmdBindVertexBuffers(cmdBuffer, bindID, 1, &vertexBuffer_, offsets);

	vk::cmdDraw(cmdBuffer, 3, 1, 0, 0);
};

void GraphicsPipeline::initBuffer()
{
	struct Vertex
	{
		float position[3];
		float color[3];
	};

	std::vector<Vertex> vertices = {
		{{1.0f,  0.6f, 0.0f}, { 1.0f, 0.0f, 0.0f}},
		{{-1.0f,  1.0f, 0.0f}, { 0.0f, 1.0f, 0.0f}},
		{{0.0f, -1.0f, 0.0f}, { 0.0f, 0.0f, 1.0f}}
	};

	vk::MemoryAllocateInfo memAlloc;
	vk::MemoryRequirements memReqs;
	void *data;

	//Generate vertex buffer
	//Setup
	vk::BufferCreateInfo bufInfo;
	bufInfo.size(sizeof(Vertex) * vertices.size());
	bufInfo.usage(vk::BufferUsageFlagBits::VertexBuffer);

	//Copy vertex data to VRAM
	VPP_CALL(vk::createBuffer(vkDevice(), &bufInfo, nullptr, &vertexBuffer_));
	vk::getBufferMemoryRequirements(vkDevice(), vertexBuffer_, &memReqs);

	memAlloc.allocationSize(memReqs.size());
	memAlloc.memoryTypeIndex(device().memoryType(memReqs.memoryTypeBits(),
		vk::MemoryPropertyFlagBits::HostVisible));

	//allocate and fill buffer memory
	VPP_CALL(vk::allocateMemory(vkDevice(), &memAlloc, nullptr, &memory_));
	VPP_CALL(vk::mapMemory(vkDevice(), memory_, 0, memAlloc.allocationSize(), {}, &data));

	std::memcpy(data, vertices.data(), sizeof(Vertex) * vertices.size());
	vk::unmapMemory(vkDevice(), memory_);

	VPP_CALL(vkBindBufferMemory(vkDevice(), vertexBuffer_, memory_, 0));

	//Binding description
	bindingDescriptions_.resize(1);
	bindingDescriptions_[0].binding(bindID);
	bindingDescriptions_[0].stride(sizeof(Vertex));
	bindingDescriptions_[0].inputRate(vk::VertexInputRate::Vertex);

	//Attribute descriptions
	//Describes memory layout and shader attribute locations
	attributeDescriptions_.resize(2);

	//Location 0 : Position
	attributeDescriptions_[0].binding(bindID);
	attributeDescriptions_[0].location(0);
	attributeDescriptions_[0].format(vk::Format::R32G32B32Sfloat);
	attributeDescriptions_[0].offset(0);

	//Location 1 : Color
	attributeDescriptions_[1].binding(bindID);
	attributeDescriptions_[1].location(1);
	attributeDescriptions_[1].format(vk::Format::R32G32B32Sfloat);
	attributeDescriptions_[1].offset(sizeof(float) * 3); //position offset

	// Assign to vertex buffer
	pipelineVertexInfo_.vertexBindingDescriptionCount(bindingDescriptions_.size());
	pipelineVertexInfo_.pVertexBindingDescriptions(bindingDescriptions_.data());
	pipelineVertexInfo_.vertexAttributeDescriptionCount(attributeDescriptions_.size());
	pipelineVertexInfo_.pVertexAttributeDescriptions(attributeDescriptions_.data());
}

void GraphicsPipeline::initPipelineLayout()
{
	vk::PipelineLayoutCreateInfo pipelineLayoutInfo;
	pipelineLayoutInfo.setLayoutCount(0);
	pipelineLayoutInfo.pSetLayouts(nullptr);

	VPP_CALL(vk::createPipelineLayout(vkDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout_));
}

std::vector<vk::PipelineShaderStageCreateInfo> GraphicsPipeline::shaderStages()
{
	std::vector<vk::PipelineShaderStageCreateInfo> stages(2);

	stages[0].module(loadShader(vkDevice(), "./vert.spv", vk::ShaderStageFlagBits::Vertex));
	stages[0].stage(vk::ShaderStageFlagBits::Vertex);
	stages[0].pName(u8"main");

	stages[1].module(loadShader(vkDevice(), "./frag.spv", vk::ShaderStageFlagBits::Fragment));
	stages[1].stage(vk::ShaderStageFlagBits::Fragment);
	stages[1].pName(u8"main");

	return stages;
}

void GraphicsPipeline::initPipeline()
{
	//draw type
	vk::PipelineInputAssemblyStateCreateInfo inputAssemblyState;
	inputAssemblyState.topology(vk::PrimitiveTopology::TriangleList);

	//Rasterization state
	vk::PipelineRasterizationStateCreateInfo rasterizationState;
	rasterizationState.polygonMode(vk::PolygonMode::Fill);
	rasterizationState.cullMode(vk::CullModeFlagBits::None);
	rasterizationState.frontFace(vk::FrontFace::CounterClockwise);
	rasterizationState.depthClampEnable(false);
	rasterizationState.rasterizerDiscardEnable(false);
	rasterizationState.depthBiasEnable(false);

	//Color blend state
	vk::PipelineColorBlendAttachmentState blendAttachmentState[1];
	blendAttachmentState[0].blendEnable(false);
	blendAttachmentState[0].colorWriteMask(
		vk::ColorComponentFlagBits::R |
		vk::ColorComponentFlagBits::G |
		vk::ColorComponentFlagBits::B |
		vk::ColorComponentFlagBits::A
	);

	vk::PipelineColorBlendStateCreateInfo colorBlendState;
	colorBlendState.attachmentCount(1);
	colorBlendState.pAttachments(blendAttachmentState);

	// Viewport state
	vk::PipelineViewportStateCreateInfo viewportState;
	viewportState.viewportCount(1);
	viewportState.scissorCount(1);

	//Enable dynamic states for viewport and scissor
	std::vector<vk::DynamicState> dynamicStateEnables;
	dynamicStateEnables.reserve(2);

	dynamicStateEnables.push_back(vk::DynamicState::Viewport);
	dynamicStateEnables.push_back(vk::DynamicState::Scissor);

	vk::PipelineDynamicStateCreateInfo dynamicState = {};
	dynamicState.pDynamicStates(dynamicStateEnables.data());
	dynamicState.dynamicStateCount(dynamicStateEnables.size());

	//depth,stencil not used atm
	vk::PipelineDepthStencilStateCreateInfo depthStencilState;

	//Multisampling, not used atm
	vk::PipelineMultisampleStateCreateInfo multisampleState;
	multisampleState.pSampleMask(nullptr);
	multisampleState.rasterizationSamples(vk::SampleCountFlagBits::e1);

	//shader stages
	auto stages = shaderStages();

	//assign info



}

void GraphicsPipeline::initDescriptorPool()
{

}

void GraphicsPipeline::initDescriptorSet()
{

}

}
