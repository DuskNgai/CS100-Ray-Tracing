#include "geometry/scene.h"

Scene::Scene(std::vector<std::shared_ptr<Geometry>> const& objects)
    : objects(objects) {}

void Scene::add_object(std::shared_ptr<Geometry> const& object) {
    objects.push_back(object);
}

void Scene::clear_objects() {
    objects.clear();
}

std::vector<std::shared_ptr<Geometry>> const& Scene::get_objects() const {
    return objects;
}

bool Scene::hit(Ray const& ray, Float t_min, Float t_max, Interaction* interaction) const {
    bool hit_anything = false;
    Float closest_so_far = t_max;
    Interaction local_interaction;
    for (auto const& object : this->objects) {
        // Update to the closest interaction.
        if (object->hit(ray, t_min, closest_so_far, &local_interaction)) {
            hit_anything = true;
            closest_so_far = local_interaction.t;
            *interaction = local_interaction;
        }
    }
    return hit_anything;
}
