# version 330

in vec3 InterpolatedColor;
in vec3 _PixelPosition;
in vec3 InterpolatedNormal;

out vec4 FragColor;
uniform vec3 _LightColor;
uniform vec3 _LightPosition;
uniform vec3 _CameraPosition;

void main()
{

vec3 _ambient = 0.1f * _LightColor;
	vec3 L= _LightPosition-_PixelPosition;
	L=normalize(L);
	vec3 _diffuse= dot(InterpolatedNormal,L)* _LightColor;
	vec3 R= reflect(-L, InterpolatedNormal);
	R=normalize(R);
	vec3 V= (_CamaraPosition-_PixelPosition);
	V=normalize(V);

	vec3 _specular = 0.5f * pow(dot(V,R),32)*_LightColor;
	vec3 PhongShading= (_ambient+ _diffuse+ _specular)* InterpolatedColor ;

	FragColor = vec4(PhongShading, 1.0f);


}

