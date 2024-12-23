#include <vulkan/vulkan.h>
#include <stdio.h>

int main()
{
    for( int i = 0; i != 2; i++ ) { printf("\n"); }
    printf("########################\n");
    printf("#    Program output    #\n");
    printf("\n");


    VkResult vkRes;




    // Get Vulkan Version
    uint32_t c_ApiVersion;
    vkRes = vkEnumerateInstanceVersion(&c_ApiVersion);
    if ( vkRes == VK_ERROR_OUT_OF_HOST_MEMORY ) { printf("[ERR][VER] OoM\n");}
    
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

    printf("API version number: %d\n", c_ApiVersion);
    printf("API variant: %d\n", c_ApiVersionVariant);
    printf("API major: %d\n", c_ApiVersionMajor);
    printf("API minor: %d\n", c_ApiVersionMinor);
    printf("API patch: %d\n", c_ApiVersionPatch);
    printf("\n");

  




    //PFN_vkVoidFunction vkGetInstanceProcAddr(NULL, )
}