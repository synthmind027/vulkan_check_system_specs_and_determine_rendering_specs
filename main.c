#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>

void c_printVulkanVersion(uint32_t c_ApiVersion) {
    int c_ApiVersionVariant = VK_API_VERSION_VARIANT(c_ApiVersion);
    int c_ApiVersionMajor = VK_API_VERSION_MAJOR(c_ApiVersion);
    int c_ApiVersionMinor = VK_API_VERSION_MINOR(c_ApiVersion);
    int c_ApiVersionPatch = VK_API_VERSION_PATCH(c_ApiVersion);  
    printf("%d.%d.%d", c_ApiVersionMajor, c_ApiVersionMinor, c_ApiVersionPatch);
}

int main()
{
    for( int i = 0; i != 2; i++ ) { printf("\n"); }
    printf("########################\n");
    printf("#    Program output    #\n");
    printf("\n");


    VkResult vkRes;
    VkInstance vkIns;



    // Get vulkan version
    uint32_t c_ApiVersion;
    vkRes = vkEnumerateInstanceVersion(&c_ApiVersion);
    if ( vkRes != VK_SUCCESS){
        if ( vkRes == VK_ERROR_OUT_OF_HOST_MEMORY ) { printf("[ERR][VER] out of host memory\n");}
    }
    
    // Note:
    // https://docs.vulkan.org/spec/latest/chapters/extensions.html#extendingvulkan-conversion-versionnumbers
    // Variant: 3bit (31-29)
    // Major: 7bit (28-22)
    // minor: 10bit (21-12)
    // patch: 12bit (11-0)
    // Note: VK_MAKE_API_VERSION(variant, major, minor, patch)

    int c_ApiVersionVariant = VK_API_VERSION_VARIANT(c_ApiVersion);
    int c_ApiVersionMajor = VK_API_VERSION_MAJOR(c_ApiVersion);
    int c_ApiVersionMinor = VK_API_VERSION_MINOR(c_ApiVersion);
    int c_ApiVersionPatch = VK_API_VERSION_PATCH(c_ApiVersion);

    printf("[Vulkan API version]\n");
    printf("Version number: %d\n", c_ApiVersion);
    printf("Version string: "); c_printVulkanVersion(c_ApiVersion); printf("\n");
    printf("Variant: %d\n", c_ApiVersionVariant);
    printf("Major: %d\n", c_ApiVersionMajor);
    printf("Minor: %d\n", c_ApiVersionMinor);
    printf("Patch: %d\n", c_ApiVersionPatch);
    printf("\n");
    printf("\n");
    printf("\n");

  




    // Get vulkan layers
    // Note:
    // https://docs.vulkan.org/spec/latest/chapters/extensions.html#extendingvulkan-layers
    uint32_t c_PropertyCount;
    vkRes = vkEnumerateInstanceLayerProperties(&c_PropertyCount,NULL);
    if ( vkRes != VK_SUCCESS ) {
        if ( vkRes == VK_INCOMPLETE) { printf("[ERR][PROP.0] incomplete\n");}
        if ( vkRes == VK_ERROR_OUT_OF_HOST_MEMORY) { printf("[ERR][PROP.0] out of host memory\n");}
        if ( vkRes == VK_ERROR_OUT_OF_DEVICE_MEMORY) { printf("[ERR][PROP.0] out of device memory\n");}
    }
    VkLayerProperties* c_VkLayerProperties = (VkLayerProperties*) malloc(sizeof(VkLayerProperties)*c_PropertyCount);
    vkRes = vkEnumerateInstanceLayerProperties(&c_PropertyCount,c_VkLayerProperties);
    if ( vkRes != VK_SUCCESS ) {
        if ( vkRes == VK_INCOMPLETE) { printf("[ERR][PROP.0] incomplete\n");}
        if ( vkRes == VK_ERROR_OUT_OF_HOST_MEMORY) { printf("[ERR][PROP.0] out of host memory\n");}
        if ( vkRes == VK_ERROR_OUT_OF_DEVICE_MEMORY) { printf("[ERR][PROP.0] out of device memory\n");}
    }
    for( int i = 0; i != c_PropertyCount; i++) {
        printf("[Layer %03d]\n", i);
        printf("Name: %s\n", c_VkLayerProperties[i].layerName); 
        printf("Vulkan version the layer was written to: "); c_printVulkanVersion(c_VkLayerProperties[i].specVersion); printf("\n");
        printf("Version of layer: %d\n", c_VkLayerProperties[i].implementationVersion);
        printf("Description: %s\n", c_VkLayerProperties[i].description);
        printf("\n");
    }



    // vkCreateInstance.pCreateInfo.pApplicationInfo


    // vkCreateInstance.pCreateInfo
    /*
    VkInstanceCreateInfo c_VkInstanceCreateInfo;
    tmp.sType = ;
    tmp.pNext = nullptr;
    tmp.flags = ;
    tmp.pApplication.info'
    */









    //PFN_vkVoidFunction vkGetInstanceProcAddr(NULL, )
}