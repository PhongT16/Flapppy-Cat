#include <visualizer/jetpack_cat.h>

using game::visualizer::JetpackCat;

void prepareSettings(JetpackCat::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(JetpackCat, ci::app::RendererGl, prepareSettings);
