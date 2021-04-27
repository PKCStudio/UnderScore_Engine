#ifndef USRenderer_HEADER
#define USRenderer_HEADER

namespace UnderScore::Engine::Renderer
{
	class USRenderer {

	public:
		virtual void Init() {}
		virtual void Render() {}
		virtual void Update() {}
		virtual void Dispose() {}


	};
}
#endif
