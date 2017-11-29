# version 330

in vec3 InterpolatedColor;
in vec3 _PixelPosition;
in vec3 InterpolatedNormal;
in vec2 InterpolatedTexCoord;

out vec4 FragColor;
uniform vec3 _LightColor;
uniform vec3 _LightPosition;
uniform vec3 _CameraPosition;

uniform sampler2D DiffuseTexture;
uniform sampler2D s2;

void main()
{

vec3 _ambient= 0.1f * _LightColor;
vec3 L= _LightPosition - _PixelPosition;
L=normalize(L);
vec3 _diffuse = dot (InterpolatedNormal, L)* _LightColor;
vec3 R= reflect (-L, InterpolatedNormal);
R= normalize(R);
vec3 V= (_CameraPosition- _PixelPosition);
V= normalize(V);
vec3 _specular= 0.5f * pow (dot(V, R),32)* _LightColor;
vec3 _phong= (_ambient + _diffuse + _specular) * InterpolatedColor;
FragColor= vec4(_phong, 1.0f) * mix( texture2D(DiffuseTexture, InterpolatedTexCoord), texture2D( s2, InterpolatedTexCoord),0.5f);

}