const DATADIR = /^win/.test(process.platform)
    ? "C:\\Users\\darko\\Documents\\GitHub\\node-vala-sdl2\\share\\game"
    : "";
/**
 *  Copyright 2017 darkoverlordofdata
 *
 * gnode is a cross-platform (gjs/nodejs)
 * module loader for the desktop
 *
 */
;
(function (scope) {
    /**
     * define: amd style loader
     */
    Object.defineProperties(scope, {
        define: { value: (function (modules) {
                /**
                 * define a module
                 *
                 * @param name module name
                 * @param deps list of dependancies
                 * @param def  module definition
                 */
                return (name, deps, def) => {
                    if (typeof name === 'string') {
                        /**
                         * load a single amd module
                         */
                        modules[name] = { id: name, exports: {} };
                        const args = [
                            /**
                             * 1st arg is the require function
                             */
                            (name) => modules[name] ? modules[name].exports : imports[name],
                            /**
                             * 2nd arg is the exports object for the module
                             */
                            modules[name].exports
                        ];
                        /**
                         * for remaining args, get the list of dependencies
                         */
                        for (let i = 2; i < deps.length; i++)
                            args.push(modules[deps[i]].exports);
                        /**
                         * invoke the module definition
                         */
                        def.apply(modules[name].exports, args);
                    }
                    else {
                        /**
                         * load a hash of pre-loaded modules
                         * such as from browserify
                         */
                        const bundle = deps();
                        for (name in bundle)
                            modules[name] = { id: name, exports: bundle[name] };
                    }
                };
            }(typeof imports === 'undefined'
                ? require(DATADIR) /* node - load index.js */
                : (function () {
                    imports.searchPath.unshift(DATADIR);
                    return imports.modules.exports;
                }()))) }
    });
    Object.defineProperties(define, {
        amd: { value: true },
        version: { value: '0.2.0' },
    });
    if (typeof console === 'undefined') {
        /**
         * gjs: define a console object
         */
        Object.defineProperties(scope, {
            console: { value: {
                    log() { print.apply(null, arguments); },
                    warn() { print.apply(null, arguments); },
                    error() { print.apply(null, arguments); },
                    info() { print.apply(null, arguments); }
                } },
        });
    }
    else {
        /**
         * node: define global print functions
         */
        Object.defineProperties(scope, {
            print: { value: function () { console.log(arguments[0]); } },
            log: { value: function () { console.info(arguments[0]); } },
            logError: { value: function () { console.warn(arguments[0]); } },
            printerr: { value: function () { console.error(arguments[0]); } },
        });
    }
    /**
     * under gjs, the window object is udefined.
     * use global instead.
     */
})(typeof window === 'undefined' ? global : window);
define("components", ["require", "exports", "entitas", "entitas", "entitas", "entitas.exceptions", "entitas.utils"], function (require, exports, entitas_1, entitas_2, entitas_3, entitas_exceptions_1, entitas_utils_1) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    var CoreComponentIds;
    (function (CoreComponentIds) {
        CoreComponentIds[CoreComponentIds["Bounds"] = 0] = "Bounds";
        CoreComponentIds[CoreComponentIds["Bullet"] = 1] = "Bullet";
        CoreComponentIds[CoreComponentIds["ColorAnimation"] = 2] = "ColorAnimation";
        CoreComponentIds[CoreComponentIds["Enemy"] = 3] = "Enemy";
        CoreComponentIds[CoreComponentIds["Expires"] = 4] = "Expires";
        CoreComponentIds[CoreComponentIds["Firing"] = 5] = "Firing";
        CoreComponentIds[CoreComponentIds["Health"] = 6] = "Health";
        CoreComponentIds[CoreComponentIds["ParallaxStar"] = 7] = "ParallaxStar";
        CoreComponentIds[CoreComponentIds["Player"] = 8] = "Player";
        CoreComponentIds[CoreComponentIds["Position"] = 9] = "Position";
        CoreComponentIds[CoreComponentIds["ScaleAnimation"] = 10] = "ScaleAnimation";
        CoreComponentIds[CoreComponentIds["SoundEffect"] = 11] = "SoundEffect";
        CoreComponentIds[CoreComponentIds["Sprite"] = 12] = "Sprite";
        CoreComponentIds[CoreComponentIds["Velocity"] = 13] = "Velocity";
        CoreComponentIds[CoreComponentIds["Score"] = 14] = "Score";
        CoreComponentIds[CoreComponentIds["Destroy"] = 15] = "Destroy";
        CoreComponentIds[CoreComponentIds["Mouse"] = 16] = "Mouse";
        CoreComponentIds[CoreComponentIds["Scale"] = 17] = "Scale";
        CoreComponentIds[CoreComponentIds["Resource"] = 18] = "Resource";
        CoreComponentIds[CoreComponentIds["Layer"] = 19] = "Layer";
        CoreComponentIds[CoreComponentIds["TotalComponents"] = 20] = "TotalComponents";
    })(CoreComponentIds = exports.CoreComponentIds || (exports.CoreComponentIds = {}));
    entitas_2.Entity.initialize(CoreComponentIds.TotalComponents, { "entities": 200, "components": 128 });
    class BoundsComponent {
    }
    exports.BoundsComponent = BoundsComponent;
    class BulletComponent {
    }
    exports.BulletComponent = BulletComponent;
    class ColorAnimationComponent {
    }
    exports.ColorAnimationComponent = ColorAnimationComponent;
    class EnemyComponent {
    }
    exports.EnemyComponent = EnemyComponent;
    class ExpiresComponent {
    }
    exports.ExpiresComponent = ExpiresComponent;
    class FiringComponent {
    }
    exports.FiringComponent = FiringComponent;
    class HealthComponent {
    }
    exports.HealthComponent = HealthComponent;
    class ParallaxStarComponent {
    }
    exports.ParallaxStarComponent = ParallaxStarComponent;
    class PlayerComponent {
    }
    exports.PlayerComponent = PlayerComponent;
    class PositionComponent {
    }
    exports.PositionComponent = PositionComponent;
    class ScaleAnimationComponent {
    }
    exports.ScaleAnimationComponent = ScaleAnimationComponent;
    class SoundEffectComponent {
    }
    exports.SoundEffectComponent = SoundEffectComponent;
    class SpriteComponent {
    }
    exports.SpriteComponent = SpriteComponent;
    class VelocityComponent {
    }
    exports.VelocityComponent = VelocityComponent;
    class ScoreComponent {
    }
    exports.ScoreComponent = ScoreComponent;
    class DestroyComponent {
    }
    exports.DestroyComponent = DestroyComponent;
    class MouseComponent {
    }
    exports.MouseComponent = MouseComponent;
    class ScaleComponent {
    }
    exports.ScaleComponent = ScaleComponent;
    class ResourceComponent {
    }
    exports.ResourceComponent = ResourceComponent;
    class LayerComponent {
    }
    exports.LayerComponent = LayerComponent;
    class Pools {
        static get allPools() {
            if (Pools._allPools == null) {
                Pools._allPools = [Pools.pool];
            }
            return Pools._allPools;
        }
        static get pool() {
            if (Pools._pool == null) {
                Pools._pool = new entitas_1.Pool(CoreComponentIds, CoreComponentIds.TotalComponents, false);
            }
            return Pools._pool;
        }
    }
    exports.Pools = Pools;
    /**
    * Entity extensions
    */
    /** Entity: Bounds methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._boundsComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._boundsComponentPool.add(new BoundsComponent());
        }
    })();
    entitas_2.Entity.clearBoundsComponentPool = function () {
        entitas_2.Entity._boundsComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'bounds', {
        get: function () {
            return this.getComponent(CoreComponentIds.Bounds);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasBounds', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Bounds);
        }
    });
    /**
      * @param radius number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addBounds = function (radius) {
        let component = entitas_2.Entity._boundsComponentPool.size() > 0 ? entitas_2.Entity._boundsComponentPool.removeLast() : new BoundsComponent();
        component.radius = radius;
        this.addComponent(CoreComponentIds.Bounds, component);
        return this;
    };
    /**
      * @param radius number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceBounds = function (radius) {
        let previousComponent = this.hasBounds ? this.bounds : null;
        let component = entitas_2.Entity._boundsComponentPool.size() > 0 ? entitas_2.Entity._boundsComponentPool.removeLast() : new BoundsComponent();
        component.radius = radius;
        this.replaceComponent(CoreComponentIds.Bounds, component);
        if (previousComponent != null) {
            entitas_2.Entity._boundsComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeBounds = function () {
        let component = this.bounds;
        this.removeComponent(CoreComponentIds.Bounds);
        entitas_2.Entity._boundsComponentPool.add(component);
        return this;
    };
    /** Entity: Bullet methods*/
    /** @type {components.BulletComponent} */
    entitas_2.Entity.bulletComponent = new BulletComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isBullet', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Bullet);
        },
        set: function (value) {
            if (value !== this.isBullet) {
                if (value) {
                    this.addComponent(CoreComponentIds.Bullet, entitas_2.Entity.bulletComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.Bullet);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setBullet = function (value) {
        this.isBullet = value;
        return this;
    };
    /** Entity: ColorAnimation methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._colorAnimationComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._colorAnimationComponentPool.add(new ColorAnimationComponent());
        }
    })();
    entitas_2.Entity.clearColorAnimationComponentPool = function () {
        entitas_2.Entity._colorAnimationComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'colorAnimation', {
        get: function () {
            return this.getComponent(CoreComponentIds.ColorAnimation);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasColorAnimation', {
        get: function () {
            return this.hasComponent(CoreComponentIds.ColorAnimation);
        }
    });
    /**
      * @param redMin number
      * @param redMax number
      * @param redSpeed number
      * @param greenMin number
      * @param greenMax number
      * @param greenSpeed number
      * @param blueMin number
      * @param blueMax number
      * @param blueSpeed number
      * @param alphaMin number
      * @param alphaMax number
      * @param alphaSpeed number
      * @param redAnimate boolean
      * @param greenAnimate boolean
      * @param blueAnimate boolean
      * @param alphaAnimate boolean
      * @param repeat boolean
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addColorAnimation = function (redMin, redMax, redSpeed, greenMin, greenMax, greenSpeed, blueMin, blueMax, blueSpeed, alphaMin, alphaMax, alphaSpeed, redAnimate, greenAnimate, blueAnimate, alphaAnimate, repeat) {
        let component = entitas_2.Entity._colorAnimationComponentPool.size() > 0 ? entitas_2.Entity._colorAnimationComponentPool.removeLast() : new ColorAnimationComponent();
        component.redMin = redMin;
        component.redMax = redMax;
        component.redSpeed = redSpeed;
        component.greenMin = greenMin;
        component.greenMax = greenMax;
        component.greenSpeed = greenSpeed;
        component.blueMin = blueMin;
        component.blueMax = blueMax;
        component.blueSpeed = blueSpeed;
        component.alphaMin = alphaMin;
        component.alphaMax = alphaMax;
        component.alphaSpeed = alphaSpeed;
        component.redAnimate = redAnimate;
        component.greenAnimate = greenAnimate;
        component.blueAnimate = blueAnimate;
        component.alphaAnimate = alphaAnimate;
        component.repeat = repeat;
        this.addComponent(CoreComponentIds.ColorAnimation, component);
        return this;
    };
    /**
      * @param redMin number
      * @param redMax number
      * @param redSpeed number
      * @param greenMin number
      * @param greenMax number
      * @param greenSpeed number
      * @param blueMin number
      * @param blueMax number
      * @param blueSpeed number
      * @param alphaMin number
      * @param alphaMax number
      * @param alphaSpeed number
      * @param redAnimate boolean
      * @param greenAnimate boolean
      * @param blueAnimate boolean
      * @param alphaAnimate boolean
      * @param repeat boolean
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceColorAnimation = function (redMin, redMax, redSpeed, greenMin, greenMax, greenSpeed, blueMin, blueMax, blueSpeed, alphaMin, alphaMax, alphaSpeed, redAnimate, greenAnimate, blueAnimate, alphaAnimate, repeat) {
        let previousComponent = this.hasColorAnimation ? this.colorAnimation : null;
        let component = entitas_2.Entity._colorAnimationComponentPool.size() > 0 ? entitas_2.Entity._colorAnimationComponentPool.removeLast() : new ColorAnimationComponent();
        component.redMin = redMin;
        component.redMax = redMax;
        component.redSpeed = redSpeed;
        component.greenMin = greenMin;
        component.greenMax = greenMax;
        component.greenSpeed = greenSpeed;
        component.blueMin = blueMin;
        component.blueMax = blueMax;
        component.blueSpeed = blueSpeed;
        component.alphaMin = alphaMin;
        component.alphaMax = alphaMax;
        component.alphaSpeed = alphaSpeed;
        component.redAnimate = redAnimate;
        component.greenAnimate = greenAnimate;
        component.blueAnimate = blueAnimate;
        component.alphaAnimate = alphaAnimate;
        component.repeat = repeat;
        this.replaceComponent(CoreComponentIds.ColorAnimation, component);
        if (previousComponent != null) {
            entitas_2.Entity._colorAnimationComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeColorAnimation = function () {
        let component = this.colorAnimation;
        this.removeComponent(CoreComponentIds.ColorAnimation);
        entitas_2.Entity._colorAnimationComponentPool.add(component);
        return this;
    };
    /** Entity: Enemy methods*/
    /** @type {components.EnemyComponent} */
    entitas_2.Entity.enemyComponent = new EnemyComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isEnemy', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Enemy);
        },
        set: function (value) {
            if (value !== this.isEnemy) {
                if (value) {
                    this.addComponent(CoreComponentIds.Enemy, entitas_2.Entity.enemyComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.Enemy);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setEnemy = function (value) {
        this.isEnemy = value;
        return this;
    };
    /** Entity: Expires methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._expiresComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._expiresComponentPool.add(new ExpiresComponent());
        }
    })();
    entitas_2.Entity.clearExpiresComponentPool = function () {
        entitas_2.Entity._expiresComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'expires', {
        get: function () {
            return this.getComponent(CoreComponentIds.Expires);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasExpires', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Expires);
        }
    });
    /**
      * @param delay number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addExpires = function (delay) {
        let component = entitas_2.Entity._expiresComponentPool.size() > 0 ? entitas_2.Entity._expiresComponentPool.removeLast() : new ExpiresComponent();
        component.delay = delay;
        this.addComponent(CoreComponentIds.Expires, component);
        return this;
    };
    /**
      * @param delay number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceExpires = function (delay) {
        let previousComponent = this.hasExpires ? this.expires : null;
        let component = entitas_2.Entity._expiresComponentPool.size() > 0 ? entitas_2.Entity._expiresComponentPool.removeLast() : new ExpiresComponent();
        component.delay = delay;
        this.replaceComponent(CoreComponentIds.Expires, component);
        if (previousComponent != null) {
            entitas_2.Entity._expiresComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeExpires = function () {
        let component = this.expires;
        this.removeComponent(CoreComponentIds.Expires);
        entitas_2.Entity._expiresComponentPool.add(component);
        return this;
    };
    /** Entity: Firing methods*/
    /** @type {components.FiringComponent} */
    entitas_2.Entity.firingComponent = new FiringComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isFiring', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Firing);
        },
        set: function (value) {
            if (value !== this.isFiring) {
                if (value) {
                    this.addComponent(CoreComponentIds.Firing, entitas_2.Entity.firingComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.Firing);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setFiring = function (value) {
        this.isFiring = value;
        return this;
    };
    /** Entity: Health methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._healthComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._healthComponentPool.add(new HealthComponent());
        }
    })();
    entitas_2.Entity.clearHealthComponentPool = function () {
        entitas_2.Entity._healthComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'health', {
        get: function () {
            return this.getComponent(CoreComponentIds.Health);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasHealth', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Health);
        }
    });
    /**
      * @param health number
      * @param maximumHealth number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addHealth = function (health, maximumHealth) {
        let component = entitas_2.Entity._healthComponentPool.size() > 0 ? entitas_2.Entity._healthComponentPool.removeLast() : new HealthComponent();
        component.health = health;
        component.maximumHealth = maximumHealth;
        this.addComponent(CoreComponentIds.Health, component);
        return this;
    };
    /**
      * @param health number
      * @param maximumHealth number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceHealth = function (health, maximumHealth) {
        let previousComponent = this.hasHealth ? this.health : null;
        let component = entitas_2.Entity._healthComponentPool.size() > 0 ? entitas_2.Entity._healthComponentPool.removeLast() : new HealthComponent();
        component.health = health;
        component.maximumHealth = maximumHealth;
        this.replaceComponent(CoreComponentIds.Health, component);
        if (previousComponent != null) {
            entitas_2.Entity._healthComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeHealth = function () {
        let component = this.health;
        this.removeComponent(CoreComponentIds.Health);
        entitas_2.Entity._healthComponentPool.add(component);
        return this;
    };
    /** Entity: ParallaxStar methods*/
    /** @type {components.ParallaxStarComponent} */
    entitas_2.Entity.parallaxStarComponent = new ParallaxStarComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isParallaxStar', {
        get: function () {
            return this.hasComponent(CoreComponentIds.ParallaxStar);
        },
        set: function (value) {
            if (value !== this.isParallaxStar) {
                if (value) {
                    this.addComponent(CoreComponentIds.ParallaxStar, entitas_2.Entity.parallaxStarComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.ParallaxStar);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setParallaxStar = function (value) {
        this.isParallaxStar = value;
        return this;
    };
    /** Entity: Player methods*/
    /** @type {components.PlayerComponent} */
    entitas_2.Entity.playerComponent = new PlayerComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isPlayer', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Player);
        },
        set: function (value) {
            if (value !== this.isPlayer) {
                if (value) {
                    this.addComponent(CoreComponentIds.Player, entitas_2.Entity.playerComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.Player);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setPlayer = function (value) {
        this.isPlayer = value;
        return this;
    };
    /** Entity: Position methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._positionComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._positionComponentPool.add(new PositionComponent());
        }
    })();
    entitas_2.Entity.clearPositionComponentPool = function () {
        entitas_2.Entity._positionComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'position', {
        get: function () {
            return this.getComponent(CoreComponentIds.Position);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasPosition', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Position);
        }
    });
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addPosition = function (x, y) {
        let component = entitas_2.Entity._positionComponentPool.size() > 0 ? entitas_2.Entity._positionComponentPool.removeLast() : new PositionComponent();
        component.x = x;
        component.y = y;
        this.addComponent(CoreComponentIds.Position, component);
        return this;
    };
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replacePosition = function (x, y) {
        let previousComponent = this.hasPosition ? this.position : null;
        let component = entitas_2.Entity._positionComponentPool.size() > 0 ? entitas_2.Entity._positionComponentPool.removeLast() : new PositionComponent();
        component.x = x;
        component.y = y;
        this.replaceComponent(CoreComponentIds.Position, component);
        if (previousComponent != null) {
            entitas_2.Entity._positionComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removePosition = function () {
        let component = this.position;
        this.removeComponent(CoreComponentIds.Position);
        entitas_2.Entity._positionComponentPool.add(component);
        return this;
    };
    /** Entity: ScaleAnimation methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._scaleAnimationComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._scaleAnimationComponentPool.add(new ScaleAnimationComponent());
        }
    })();
    entitas_2.Entity.clearScaleAnimationComponentPool = function () {
        entitas_2.Entity._scaleAnimationComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'scaleAnimation', {
        get: function () {
            return this.getComponent(CoreComponentIds.ScaleAnimation);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasScaleAnimation', {
        get: function () {
            return this.hasComponent(CoreComponentIds.ScaleAnimation);
        }
    });
    /**
      * @param min number
      * @param max number
      * @param speed number
      * @param repeat boolean
      * @param active boolean
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addScaleAnimation = function (min, max, speed, repeat, active) {
        let component = entitas_2.Entity._scaleAnimationComponentPool.size() > 0 ? entitas_2.Entity._scaleAnimationComponentPool.removeLast() : new ScaleAnimationComponent();
        component.min = min;
        component.max = max;
        component.speed = speed;
        component.repeat = repeat;
        component.active = active;
        this.addComponent(CoreComponentIds.ScaleAnimation, component);
        return this;
    };
    /**
      * @param min number
      * @param max number
      * @param speed number
      * @param repeat boolean
      * @param active boolean
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceScaleAnimation = function (min, max, speed, repeat, active) {
        let previousComponent = this.hasScaleAnimation ? this.scaleAnimation : null;
        let component = entitas_2.Entity._scaleAnimationComponentPool.size() > 0 ? entitas_2.Entity._scaleAnimationComponentPool.removeLast() : new ScaleAnimationComponent();
        component.min = min;
        component.max = max;
        component.speed = speed;
        component.repeat = repeat;
        component.active = active;
        this.replaceComponent(CoreComponentIds.ScaleAnimation, component);
        if (previousComponent != null) {
            entitas_2.Entity._scaleAnimationComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeScaleAnimation = function () {
        let component = this.scaleAnimation;
        this.removeComponent(CoreComponentIds.ScaleAnimation);
        entitas_2.Entity._scaleAnimationComponentPool.add(component);
        return this;
    };
    /** Entity: SoundEffect methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._soundEffectComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._soundEffectComponentPool.add(new SoundEffectComponent());
        }
    })();
    entitas_2.Entity.clearSoundEffectComponentPool = function () {
        entitas_2.Entity._soundEffectComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'soundEffect', {
        get: function () {
            return this.getComponent(CoreComponentIds.SoundEffect);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasSoundEffect', {
        get: function () {
            return this.hasComponent(CoreComponentIds.SoundEffect);
        }
    });
    /**
      * @param effect number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addSoundEffect = function (effect) {
        let component = entitas_2.Entity._soundEffectComponentPool.size() > 0 ? entitas_2.Entity._soundEffectComponentPool.removeLast() : new SoundEffectComponent();
        component.effect = effect;
        this.addComponent(CoreComponentIds.SoundEffect, component);
        return this;
    };
    /**
      * @param effect number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceSoundEffect = function (effect) {
        let previousComponent = this.hasSoundEffect ? this.soundEffect : null;
        let component = entitas_2.Entity._soundEffectComponentPool.size() > 0 ? entitas_2.Entity._soundEffectComponentPool.removeLast() : new SoundEffectComponent();
        component.effect = effect;
        this.replaceComponent(CoreComponentIds.SoundEffect, component);
        if (previousComponent != null) {
            entitas_2.Entity._soundEffectComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeSoundEffect = function () {
        let component = this.soundEffect;
        this.removeComponent(CoreComponentIds.SoundEffect);
        entitas_2.Entity._soundEffectComponentPool.add(component);
        return this;
    };
    /** Entity: Sprite methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._spriteComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._spriteComponentPool.add(new SpriteComponent());
        }
    })();
    entitas_2.Entity.clearSpriteComponentPool = function () {
        entitas_2.Entity._spriteComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'sprite', {
        get: function () {
            return this.getComponent(CoreComponentIds.Sprite);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasSprite', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Sprite);
        }
    });
    /**
      * @param layer number
      * @param object Object
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addSprite = function (layer, object) {
        let component = entitas_2.Entity._spriteComponentPool.size() > 0 ? entitas_2.Entity._spriteComponentPool.removeLast() : new SpriteComponent();
        component.layer = layer;
        component.object = object;
        this.addComponent(CoreComponentIds.Sprite, component);
        return this;
    };
    /**
      * @param layer number
      * @param object Object
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceSprite = function (layer, object) {
        let previousComponent = this.hasSprite ? this.sprite : null;
        let component = entitas_2.Entity._spriteComponentPool.size() > 0 ? entitas_2.Entity._spriteComponentPool.removeLast() : new SpriteComponent();
        component.layer = layer;
        component.object = object;
        this.replaceComponent(CoreComponentIds.Sprite, component);
        if (previousComponent != null) {
            entitas_2.Entity._spriteComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeSprite = function () {
        let component = this.sprite;
        this.removeComponent(CoreComponentIds.Sprite);
        entitas_2.Entity._spriteComponentPool.add(component);
        return this;
    };
    /** Entity: Velocity methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._velocityComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._velocityComponentPool.add(new VelocityComponent());
        }
    })();
    entitas_2.Entity.clearVelocityComponentPool = function () {
        entitas_2.Entity._velocityComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'velocity', {
        get: function () {
            return this.getComponent(CoreComponentIds.Velocity);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasVelocity', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Velocity);
        }
    });
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addVelocity = function (x, y) {
        let component = entitas_2.Entity._velocityComponentPool.size() > 0 ? entitas_2.Entity._velocityComponentPool.removeLast() : new VelocityComponent();
        component.x = x;
        component.y = y;
        this.addComponent(CoreComponentIds.Velocity, component);
        return this;
    };
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceVelocity = function (x, y) {
        let previousComponent = this.hasVelocity ? this.velocity : null;
        let component = entitas_2.Entity._velocityComponentPool.size() > 0 ? entitas_2.Entity._velocityComponentPool.removeLast() : new VelocityComponent();
        component.x = x;
        component.y = y;
        this.replaceComponent(CoreComponentIds.Velocity, component);
        if (previousComponent != null) {
            entitas_2.Entity._velocityComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeVelocity = function () {
        let component = this.velocity;
        this.removeComponent(CoreComponentIds.Velocity);
        entitas_2.Entity._velocityComponentPool.add(component);
        return this;
    };
    /** Entity: Score methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._scoreComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._scoreComponentPool.add(new ScoreComponent());
        }
    })();
    entitas_2.Entity.clearScoreComponentPool = function () {
        entitas_2.Entity._scoreComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'score', {
        get: function () {
            return this.getComponent(CoreComponentIds.Score);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasScore', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Score);
        }
    });
    /**
      * @param value number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addScore = function (value) {
        let component = entitas_2.Entity._scoreComponentPool.size() > 0 ? entitas_2.Entity._scoreComponentPool.removeLast() : new ScoreComponent();
        component.value = value;
        this.addComponent(CoreComponentIds.Score, component);
        return this;
    };
    /**
      * @param value number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceScore = function (value) {
        let previousComponent = this.hasScore ? this.score : null;
        let component = entitas_2.Entity._scoreComponentPool.size() > 0 ? entitas_2.Entity._scoreComponentPool.removeLast() : new ScoreComponent();
        component.value = value;
        this.replaceComponent(CoreComponentIds.Score, component);
        if (previousComponent != null) {
            entitas_2.Entity._scoreComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeScore = function () {
        let component = this.score;
        this.removeComponent(CoreComponentIds.Score);
        entitas_2.Entity._scoreComponentPool.add(component);
        return this;
    };
    /** Entity: Destroy methods*/
    /** @type {components.DestroyComponent} */
    entitas_2.Entity.destroyComponent = new DestroyComponent();
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'isDestroy', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Destroy);
        },
        set: function (value) {
            if (value !== this.isDestroy) {
                if (value) {
                    this.addComponent(CoreComponentIds.Destroy, entitas_2.Entity.destroyComponent);
                }
                else {
                    this.removeComponent(CoreComponentIds.Destroy);
                }
            }
        }
    });
    /**
     * @param {boolean} value
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.setDestroy = function (value) {
        this.isDestroy = value;
        return this;
    };
    /** Entity: Mouse methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._mouseComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._mouseComponentPool.add(new MouseComponent());
        }
    })();
    entitas_2.Entity.clearMouseComponentPool = function () {
        entitas_2.Entity._mouseComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'mouse', {
        get: function () {
            return this.getComponent(CoreComponentIds.Mouse);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasMouse', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Mouse);
        }
    });
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addMouse = function (x, y) {
        let component = entitas_2.Entity._mouseComponentPool.size() > 0 ? entitas_2.Entity._mouseComponentPool.removeLast() : new MouseComponent();
        component.x = x;
        component.y = y;
        this.addComponent(CoreComponentIds.Mouse, component);
        return this;
    };
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceMouse = function (x, y) {
        let previousComponent = this.hasMouse ? this.mouse : null;
        let component = entitas_2.Entity._mouseComponentPool.size() > 0 ? entitas_2.Entity._mouseComponentPool.removeLast() : new MouseComponent();
        component.x = x;
        component.y = y;
        this.replaceComponent(CoreComponentIds.Mouse, component);
        if (previousComponent != null) {
            entitas_2.Entity._mouseComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeMouse = function () {
        let component = this.mouse;
        this.removeComponent(CoreComponentIds.Mouse);
        entitas_2.Entity._mouseComponentPool.add(component);
        return this;
    };
    /** Entity: Scale methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._scaleComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._scaleComponentPool.add(new ScaleComponent());
        }
    })();
    entitas_2.Entity.clearScaleComponentPool = function () {
        entitas_2.Entity._scaleComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'scale', {
        get: function () {
            return this.getComponent(CoreComponentIds.Scale);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasScale', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Scale);
        }
    });
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addScale = function (x, y) {
        let component = entitas_2.Entity._scaleComponentPool.size() > 0 ? entitas_2.Entity._scaleComponentPool.removeLast() : new ScaleComponent();
        component.x = x;
        component.y = y;
        this.addComponent(CoreComponentIds.Scale, component);
        return this;
    };
    /**
      * @param x number
      * @param y number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceScale = function (x, y) {
        let previousComponent = this.hasScale ? this.scale : null;
        let component = entitas_2.Entity._scaleComponentPool.size() > 0 ? entitas_2.Entity._scaleComponentPool.removeLast() : new ScaleComponent();
        component.x = x;
        component.y = y;
        this.replaceComponent(CoreComponentIds.Scale, component);
        if (previousComponent != null) {
            entitas_2.Entity._scaleComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeScale = function () {
        let component = this.scale;
        this.removeComponent(CoreComponentIds.Scale);
        entitas_2.Entity._scaleComponentPool.add(component);
        return this;
    };
    /** Entity: Resource methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._resourceComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._resourceComponentPool.add(new ResourceComponent());
        }
    })();
    entitas_2.Entity.clearResourceComponentPool = function () {
        entitas_2.Entity._resourceComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'resource', {
        get: function () {
            return this.getComponent(CoreComponentIds.Resource);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasResource', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Resource);
        }
    });
    /**
      * @param name string
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addResource = function (name) {
        let component = entitas_2.Entity._resourceComponentPool.size() > 0 ? entitas_2.Entity._resourceComponentPool.removeLast() : new ResourceComponent();
        component.name = name;
        this.addComponent(CoreComponentIds.Resource, component);
        return this;
    };
    /**
      * @param name string
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceResource = function (name) {
        let previousComponent = this.hasResource ? this.resource : null;
        let component = entitas_2.Entity._resourceComponentPool.size() > 0 ? entitas_2.Entity._resourceComponentPool.removeLast() : new ResourceComponent();
        component.name = name;
        this.replaceComponent(CoreComponentIds.Resource, component);
        if (previousComponent != null) {
            entitas_2.Entity._resourceComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeResource = function () {
        let component = this.resource;
        this.removeComponent(CoreComponentIds.Resource);
        entitas_2.Entity._resourceComponentPool.add(component);
        return this;
    };
    /** Entity: Layer methods*/
    /** @type {entitas.utils.Bag} */
    entitas_2.Entity._layerComponentPool = new entitas_utils_1.Bag();
    (function () {
        for (let i = 0; i < 128; i++) {
            entitas_2.Entity._layerComponentPool.add(new LayerComponent());
        }
    })();
    entitas_2.Entity.clearLayerComponentPool = function () {
        entitas_2.Entity._layerComponentPool.clear();
    };
    /** @type [object Object]Component} */
    Object.defineProperty(entitas_2.Entity.prototype, 'layer', {
        get: function () {
            return this.getComponent(CoreComponentIds.Layer);
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_2.Entity.prototype, 'hasLayer', {
        get: function () {
            return this.hasComponent(CoreComponentIds.Layer);
        }
    });
    /**
      * @param ordinal number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.addLayer = function (ordinal) {
        let component = entitas_2.Entity._layerComponentPool.size() > 0 ? entitas_2.Entity._layerComponentPool.removeLast() : new LayerComponent();
        component.ordinal = ordinal;
        this.addComponent(CoreComponentIds.Layer, component);
        return this;
    };
    /**
      * @param ordinal number
      * @return entitas.Entity
      */
    entitas_2.Entity.prototype.replaceLayer = function (ordinal) {
        let previousComponent = this.hasLayer ? this.layer : null;
        let component = entitas_2.Entity._layerComponentPool.size() > 0 ? entitas_2.Entity._layerComponentPool.removeLast() : new LayerComponent();
        component.ordinal = ordinal;
        this.replaceComponent(CoreComponentIds.Layer, component);
        if (previousComponent != null) {
            entitas_2.Entity._layerComponentPool.add(previousComponent);
        }
        return this;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_2.Entity.prototype.removeLayer = function () {
        let component = this.layer;
        this.removeComponent(CoreComponentIds.Layer);
        entitas_2.Entity._layerComponentPool.add(component);
        return this;
    };
    /** Matcher: Bounds methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherBounds = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Bounds', {
        get: function () {
            if (entitas_3.Matcher._matcherBounds == null) {
                entitas_3.Matcher._matcherBounds = entitas_3.Matcher.allOf(CoreComponentIds.Bounds);
            }
            return entitas_3.Matcher._matcherBounds;
        }
    });
    /** Matcher: Bullet methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherBullet = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Bullet', {
        get: function () {
            if (entitas_3.Matcher._matcherBullet == null) {
                entitas_3.Matcher._matcherBullet = entitas_3.Matcher.allOf(CoreComponentIds.Bullet);
            }
            return entitas_3.Matcher._matcherBullet;
        }
    });
    /** Matcher: ColorAnimation methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherColorAnimation = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'ColorAnimation', {
        get: function () {
            if (entitas_3.Matcher._matcherColorAnimation == null) {
                entitas_3.Matcher._matcherColorAnimation = entitas_3.Matcher.allOf(CoreComponentIds.ColorAnimation);
            }
            return entitas_3.Matcher._matcherColorAnimation;
        }
    });
    /** Matcher: Enemy methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherEnemy = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Enemy', {
        get: function () {
            if (entitas_3.Matcher._matcherEnemy == null) {
                entitas_3.Matcher._matcherEnemy = entitas_3.Matcher.allOf(CoreComponentIds.Enemy);
            }
            return entitas_3.Matcher._matcherEnemy;
        }
    });
    /** Matcher: Expires methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherExpires = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Expires', {
        get: function () {
            if (entitas_3.Matcher._matcherExpires == null) {
                entitas_3.Matcher._matcherExpires = entitas_3.Matcher.allOf(CoreComponentIds.Expires);
            }
            return entitas_3.Matcher._matcherExpires;
        }
    });
    /** Matcher: Firing methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherFiring = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Firing', {
        get: function () {
            if (entitas_3.Matcher._matcherFiring == null) {
                entitas_3.Matcher._matcherFiring = entitas_3.Matcher.allOf(CoreComponentIds.Firing);
            }
            return entitas_3.Matcher._matcherFiring;
        }
    });
    /** Matcher: Health methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherHealth = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Health', {
        get: function () {
            if (entitas_3.Matcher._matcherHealth == null) {
                entitas_3.Matcher._matcherHealth = entitas_3.Matcher.allOf(CoreComponentIds.Health);
            }
            return entitas_3.Matcher._matcherHealth;
        }
    });
    /** Matcher: ParallaxStar methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherParallaxStar = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'ParallaxStar', {
        get: function () {
            if (entitas_3.Matcher._matcherParallaxStar == null) {
                entitas_3.Matcher._matcherParallaxStar = entitas_3.Matcher.allOf(CoreComponentIds.ParallaxStar);
            }
            return entitas_3.Matcher._matcherParallaxStar;
        }
    });
    /** Matcher: Player methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherPlayer = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Player', {
        get: function () {
            if (entitas_3.Matcher._matcherPlayer == null) {
                entitas_3.Matcher._matcherPlayer = entitas_3.Matcher.allOf(CoreComponentIds.Player);
            }
            return entitas_3.Matcher._matcherPlayer;
        }
    });
    /** Matcher: Position methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherPosition = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Position', {
        get: function () {
            if (entitas_3.Matcher._matcherPosition == null) {
                entitas_3.Matcher._matcherPosition = entitas_3.Matcher.allOf(CoreComponentIds.Position);
            }
            return entitas_3.Matcher._matcherPosition;
        }
    });
    /** Matcher: ScaleAnimation methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherScaleAnimation = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'ScaleAnimation', {
        get: function () {
            if (entitas_3.Matcher._matcherScaleAnimation == null) {
                entitas_3.Matcher._matcherScaleAnimation = entitas_3.Matcher.allOf(CoreComponentIds.ScaleAnimation);
            }
            return entitas_3.Matcher._matcherScaleAnimation;
        }
    });
    /** Matcher: SoundEffect methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherSoundEffect = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'SoundEffect', {
        get: function () {
            if (entitas_3.Matcher._matcherSoundEffect == null) {
                entitas_3.Matcher._matcherSoundEffect = entitas_3.Matcher.allOf(CoreComponentIds.SoundEffect);
            }
            return entitas_3.Matcher._matcherSoundEffect;
        }
    });
    /** Matcher: Sprite methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherSprite = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Sprite', {
        get: function () {
            if (entitas_3.Matcher._matcherSprite == null) {
                entitas_3.Matcher._matcherSprite = entitas_3.Matcher.allOf(CoreComponentIds.Sprite);
            }
            return entitas_3.Matcher._matcherSprite;
        }
    });
    /** Matcher: Velocity methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherVelocity = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Velocity', {
        get: function () {
            if (entitas_3.Matcher._matcherVelocity == null) {
                entitas_3.Matcher._matcherVelocity = entitas_3.Matcher.allOf(CoreComponentIds.Velocity);
            }
            return entitas_3.Matcher._matcherVelocity;
        }
    });
    /** Matcher: Score methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherScore = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Score', {
        get: function () {
            if (entitas_3.Matcher._matcherScore == null) {
                entitas_3.Matcher._matcherScore = entitas_3.Matcher.allOf(CoreComponentIds.Score);
            }
            return entitas_3.Matcher._matcherScore;
        }
    });
    /** Matcher: Destroy methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherDestroy = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Destroy', {
        get: function () {
            if (entitas_3.Matcher._matcherDestroy == null) {
                entitas_3.Matcher._matcherDestroy = entitas_3.Matcher.allOf(CoreComponentIds.Destroy);
            }
            return entitas_3.Matcher._matcherDestroy;
        }
    });
    /** Matcher: Mouse methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherMouse = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Mouse', {
        get: function () {
            if (entitas_3.Matcher._matcherMouse == null) {
                entitas_3.Matcher._matcherMouse = entitas_3.Matcher.allOf(CoreComponentIds.Mouse);
            }
            return entitas_3.Matcher._matcherMouse;
        }
    });
    /** Matcher: Scale methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherScale = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Scale', {
        get: function () {
            if (entitas_3.Matcher._matcherScale == null) {
                entitas_3.Matcher._matcherScale = entitas_3.Matcher.allOf(CoreComponentIds.Scale);
            }
            return entitas_3.Matcher._matcherScale;
        }
    });
    /** Matcher: Resource methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherResource = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Resource', {
        get: function () {
            if (entitas_3.Matcher._matcherResource == null) {
                entitas_3.Matcher._matcherResource = entitas_3.Matcher.allOf(CoreComponentIds.Resource);
            }
            return entitas_3.Matcher._matcherResource;
        }
    });
    /** Matcher: Layer methods*/
    /** @type {entitas.Matcher} */
    entitas_3.Matcher._matcherLayer = null;
    /** @type {entitas.Matcher} */
    Object.defineProperty(entitas_3.Matcher, 'Layer', {
        get: function () {
            if (entitas_3.Matcher._matcherLayer == null) {
                entitas_3.Matcher._matcherLayer = entitas_3.Matcher.allOf(CoreComponentIds.Layer);
            }
            return entitas_3.Matcher._matcherLayer;
        }
    });
    /** Pool: Score methods*/
    /** @type {entitas.Pool} */
    Object.defineProperty(entitas_1.Pool.prototype, 'scoreEntity', {
        get: function () {
            return this.getGroup(entitas_3.Matcher.Score).getSingleEntity();
        }
    });
    /** @type {components.ScoreComponent} */
    Object.defineProperty(entitas_1.Pool.prototype, 'score', {
        get: function () {
            return this.scoreEntity.score;
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_1.Pool.prototype, 'hasScore', {
        get: function () {
            return this.scoreEntity != undefined;
        }
    });
    /**
     * @param {number} value
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.setScore = function (value) {
        if (this.hasScore) {
            throw new entitas_exceptions_1.SingleEntityException(entitas_3.Matcher.Score);
        }
        let entity = this.createEntity('Score');
        entity.addScore(value);
        return entity;
    };
    /**
     * @param {number} value
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.replaceScore = function (value) {
        let entity = this.scoreEntity;
        if (entity == null) {
            entity = this.setScore(value);
        }
        else {
            entity.replaceScore(value);
        }
        return entity;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.removeScore = function () {
        this.destroyEntity(this.scoreEntity);
    };
    /** Pool: Mouse methods*/
    /** @type {entitas.Pool} */
    Object.defineProperty(entitas_1.Pool.prototype, 'mouseEntity', {
        get: function () {
            return this.getGroup(entitas_3.Matcher.Mouse).getSingleEntity();
        }
    });
    /** @type {components.MouseComponent} */
    Object.defineProperty(entitas_1.Pool.prototype, 'mouse', {
        get: function () {
            return this.mouseEntity.mouse;
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_1.Pool.prototype, 'hasMouse', {
        get: function () {
            return this.mouseEntity != undefined;
        }
    });
    /**
     * @param {number} value
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.setMouse = function (value) {
        if (this.hasMouse) {
            throw new entitas_exceptions_1.SingleEntityException(entitas_3.Matcher.Mouse);
        }
        let entity = this.createEntity('Mouse');
        entity.addMouse(value);
        return entity;
    };
    /**
     * @param {number} value
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.replaceMouse = function (value) {
        let entity = this.mouseEntity;
        if (entity == null) {
            entity = this.setMouse(value);
        }
        else {
            entity.replaceMouse(value);
        }
        return entity;
    };
    /**
     * @returns {entitas.Entity}
     */
    entitas_1.Pool.prototype.removeMouse = function () {
        this.destroyEntity(this.mouseEntity);
    };
    /** Pool: Firing methods*/
    /** @type {entitas.Pool} */
    Object.defineProperty(entitas_1.Pool.prototype, 'firingEntity', {
        get: function () {
            return this.getGroup(entitas_3.Matcher.Firing).getSingleEntity();
        }
    });
    /** @type {boolean} */
    Object.defineProperty(entitas_1.Pool.prototype, 'isFiring', {
        get: function () {
            return this.firingEntity != null;
        },
        set: function (value) {
            let entity = this.firingEntity;
            if (value != (entity != null)) {
                if (value) {
                    this.createEntity('Firing').isFiring = true;
                }
                else {
                    this.destroyEntity(entity);
                }
            }
        }
    });
});
define("systems/MovementSystem", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_1, entitas_4) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class MovementSystem {
        execute() {
            let entities = this.group.getEntities();
            for (let e of entities) {
                let delta = Sdx_1.Sdx.app.deltaTime;
                e.position.x += (e.velocity.x * delta);
                e.position.y -= (e.velocity.y * delta);
                let sprite = e.sprite.object;
                sprite.x = e.position.x;
                sprite.y = e.position.y;
            }
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_4.Matcher.allOf(entitas_4.Matcher.Position, entitas_4.Matcher.Velocity));
        }
    }
    exports.MovementSystem = MovementSystem;
});
define("systems/PlayerInputSystem", ["require", "exports", "Sdx", "Sdx", "entitas"], function (require, exports, Sdx_2, Sdx_3, entitas_5) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class PlayerInputSystem {
        constructor() {
            this.timeToFire = 0;
        }
        execute() {
            let entities = this.group.getEntities();
            if (entities.length === 0)
                return;
            let e = entities[0];
            let position = e.position;
            position.x = Sdx_2.Sdx.app.mouseX;
            position.y = Sdx_2.Sdx.app.mouseY;
            if (Sdx_2.Sdx.app.mouseDown || Sdx_2.Sdx.app.getKey(Sdx_3.Input.Keys.z)) {
                if (this.timeToFire <= 0) {
                    this.pool.createBullet(position.x - 27, position.y + 2);
                    this.pool.createBullet(position.x + 27, position.y + 2);
                    this.timeToFire = PlayerInputSystem.FireRate;
                }
            }
            if (this.timeToFire > 0) {
                this.timeToFire -= Sdx_2.Sdx.app.deltaTime;
                if (this.timeToFire < 0) {
                    this.timeToFire = 0;
                }
            }
        }
        initialize() {
            this.pool.createPlayer();
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_5.Matcher.allOf(entitas_5.Matcher.Player));
        }
    }
    PlayerInputSystem.FireRate = .1;
    exports.PlayerInputSystem = PlayerInputSystem;
});
/**
 * Pool Extensions
 *
 * this is the entity factory
 */
define("extensions", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_4, entitas_6) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    var Layer;
    (function (Layer) {
        Layer[Layer["BACKGROUND"] = 0] = "BACKGROUND";
        Layer[Layer["ENEMY1"] = 1] = "ENEMY1";
        Layer[Layer["ENEMY2"] = 2] = "ENEMY2";
        Layer[Layer["ENEMY3"] = 3] = "ENEMY3";
        Layer[Layer["PLAYER"] = 4] = "PLAYER";
        Layer[Layer["PARTICLES"] = 5] = "PARTICLES";
    })(Layer = exports.Layer || (exports.Layer = {}));
    var Effect;
    (function (Effect) {
        Effect[Effect["PEW"] = 0] = "PEW";
        Effect[Effect["ASPLODE"] = 1] = "ASPLODE";
        Effect[Effect["SMALLASPLODE"] = 2] = "SMALLASPLODE";
    })(Effect = exports.Effect || (exports.Effect = {}));
    const Tau = Math.PI * 2;
    /**
     * Create the player
     */
    entitas_6.Pool.prototype.createPlayer = function () {
        this.createEntity('Player')
            .addBounds(43)
            .addVelocity(0, 0)
            .addPosition(~~(Sdx_4.Sdx.app.width / 4), ~~(Sdx_4.Sdx.app.height - 80))
            .addLayer(Layer.PLAYER)
            .addResource('spaceshipspr')
            .setPlayer(true);
    };
    /**
     * Create a bullet at (x,y)
     *
     * @param x
     * @param y
     */
    entitas_6.Pool.prototype.createBullet = function (x, y) {
        this.createEntity('Bullet')
            .addPosition(~~x, ~~y)
            .addVelocity(0, 800)
            .addBounds(5)
            .addExpires(1)
            .addSoundEffect(Effect.PEW)
            .addLayer(Layer.PARTICLES)
            .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
            .addResource('bullet')
            .setBullet(true);
    };
    /**
     * Create a particle at (x,y)
     *
     * @param x
     * @param y
     */
    entitas_6.Pool.prototype.createParticle = function (x, y) {
        const radians = Math.random() * Tau;
        const magnitude = Math.random() * 200;
        const velocityX = magnitude * Math.cos(radians);
        const velocityY = magnitude * Math.sin(radians);
        const scale = Math.random();
        this.createEntity('Particle')
            .addExpires(1)
            .addPosition(~~x, ~~y)
            .addVelocity(velocityX, velocityY)
            .addScale(scale, scale)
            .addLayer(Layer.PARTICLES)
            .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
            .addResource('star');
    };
    /**
     * Create a small explosion at (x,y)
     *
     * @param x
     * @param y
     */
    entitas_6.Pool.prototype.createSmallExplosion = function (x, y) {
        //                tint: {r:0xd2, g:0xfa, b:0xd2, a:0xfa},
        const scale = .2;
        this.createEntity('SmallExp')
            .addExpires(0.5)
            .addScaleAnimation(scale / 100, scale, -3, false, true)
            .addPosition(~~x, ~~y)
            .addScale(scale, scale)
            .addLayer(Layer.PARTICLES)
            .addSoundEffect(Effect.SMALLASPLODE)
            .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
            .addResource('explosion');
    };
    /**
     * Create a big explosion at (x,y)
     *
     * @param x
     * @param y
     */
    entitas_6.Pool.prototype.createBigExplosion = function (x, y) {
        const scale = .5;
        this.createEntity('BigExp')
            .addExpires(0.5)
            .addScaleAnimation(scale / 100, scale, -3, false, true)
            .addPosition(~~x, ~~y)
            .addScale(scale, scale)
            .addLayer(Layer.PARTICLES)
            .addSoundEffect(Effect.ASPLODE)
            .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
            .addResource('explosion');
    };
    /**
     * Create enemy ship #1
     *
     */
    entitas_6.Pool.prototype.createEnemy1 = function () {
        const x = Math.random() * (Sdx_4.Sdx.app.width - 40) + 20;
        const y = 0; //Sdx.app.height - 200 ///2 - 200
        this.createEntity("Enemy1")
            .addBounds(20)
            .addPosition(~~x, ~~y)
            .addVelocity(0, -40)
            .addLayer(Layer.ENEMY1)
            .addResource('enemy1')
            .addHealth(10, 10)
            .setEnemy(true);
    };
    /**
     * Create enemy ship #2
     */
    entitas_6.Pool.prototype.createEnemy2 = function () {
        const x = Math.random() * (Sdx_4.Sdx.app.width - 80) + 40;
        const y = 0; //Sdx.app.height - 100 ///2 - 100
        this.createEntity("Enemy2")
            .addBounds(40)
            .addPosition(~~x, ~~y)
            .addVelocity(0, -30)
            .addLayer(Layer.ENEMY2)
            .addResource('enemy2')
            .addHealth(20, 20)
            .setEnemy(true);
    };
    /**
     * Create enemy ship #3
     */
    entitas_6.Pool.prototype.createEnemy3 = function () {
        const x = Math.random() * (Sdx_4.Sdx.app.width - 140) + 70;
        const y = 0; //Sdx.app.height - 50 ///2 - 50
        this.createEntity("Enemy3")
            .addBounds(70)
            .addPosition(~~x, ~~y)
            .addVelocity(0, -20)
            .addLayer(Layer.ENEMY3)
            .addResource('enemy3')
            .addHealth(60, 60)
            .setEnemy(true);
    };
});
define("systems/SoundEffectSystem", ["require", "exports", "entitas", "extensions", "Sdx"], function (require, exports, entitas_7, extensions_1, sdx) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class SoundEffectSystem {
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_7.Matcher.allOf(entitas_7.Matcher.SoundEffect));
        }
        execute() {
            let entities = this.group.getEntities();
            for (let e of entities) {
                let soundEffect = e.soundEffect;
                switch (soundEffect.effect) {
                    case extensions_1.Effect.PEW:
                        this.pew.play(0);
                        break;
                    case extensions_1.Effect.ASPLODE:
                        this.asplode.play(0);
                        break;
                    case extensions_1.Effect.SMALLASPLODE:
                        this.smallasplode.play(0);
                        break;
                }
                e.removeSoundEffect();
            }
        }
        initialize() {
            this.pew = sdx.createSound("sounds/pew.wav");
            this.asplode = sdx.createSound("sounds/asplode.wav");
            this.smallasplode = sdx.createSound("sounds/smallasplode.wav");
        }
    }
    exports.SoundEffectSystem = SoundEffectSystem;
});
define("systems/CollisionSystem", ["require", "exports", "entitas"], function (require, exports, entitas_8) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class CollisionSystem {
        setPool(pool) {
            this.pool = pool;
        }
        /**
         * Check for Collision
         */
        execute() {
            let collisionPairs = this.collisionPairs;
            for (let pair of collisionPairs)
                pair.checkForCollisions();
        }
        /**
         * Create collision handlers
         */
        initialize() {
            this.pool.setScore(0);
            this.bullets = this.pool.getGroup(entitas_8.Matcher.Bullet);
            this.enemies = this.pool.getGroup(entitas_8.Matcher.Enemy);
            /** Check for bullets hitting enemy ship */
            this.collisionPairs = [];
            this.collisionPairs.push(new CollisionPair(this, this.bullets, this.enemies, {
                handleCollision: (bullet, ship) => {
                    // let bp: PositionComponent = bullet.position
                    // let health: HealthComponent = ship.health
                    // let position: PositionComponent = ship.position
                    let bp = bullet.position;
                    let health = ship.health;
                    let position = ship.position;
                    let x = bp.x;
                    let y = bp.y;
                    this.pool.createSmallExplosion(x, y);
                    let i = 3;
                    while (--i > 0)
                        this.pool.createParticle(x, y);
                    bullet.setDestroy(true);
                    health.health -= 2;
                    if (health.health < 0) {
                        let score = (this.pool.score);
                        this.pool.replaceScore(score.value + ship.health.maximumHealth);
                        ship.setDestroy(true);
                        this.pool.createBigExplosion(position.x, position.y);
                    }
                }
            }));
        }
    }
    exports.CollisionSystem = CollisionSystem;
    /**
     *
     */
    class CollisionPair {
        constructor(cs, group1, group2, handler) {
            this.groupEntitiesA = group1;
            this.groupEntitiesB = group2;
            this.handler = handler;
            this.cs = cs;
        }
        checkForCollisions() {
            let handler = this.handler;
            let groupEntitiesA = this.groupEntitiesA.getEntities();
            let groupEntitiesB = this.groupEntitiesB.getEntities();
            let sizeA = groupEntitiesA.length;
            let sizeB = groupEntitiesB.length;
            for (let a = 0; sizeA > a; a++) {
                let entityA = groupEntitiesA[a];
                for (let b = 0; sizeB > b; b++) {
                    let entityB = groupEntitiesB[b];
                    if (this.collisionExists(entityA, entityB)) {
                        handler.handleCollision(entityA, entityB);
                    }
                }
            }
        }
        collisionExists(e1, e2) {
            if (e1 === null || e2 === null)
                return false;
            let p1 = e1.position;
            let p2 = e2.position;
            let b1 = e1.bounds;
            let b2 = e2.bounds;
            let a = p1.x - p2.x;
            let b = p1.y - p2.y;
            return Math.sqrt(a * a + b * b) - (b1.radius) < (b2.radius);
        }
    }
});
define("systems/ExpiringSystem", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_5, entitas_9) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class ExpiringSystem {
        execute() {
            let pool = this.pool;
            let entities = this.group.getEntities();
            for (let e of entities) {
                if ((e.expires.delay -= Sdx_5.Sdx.app.deltaTime) <= 0) {
                    e.isDestroy = true;
                }
            }
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_9.Matcher.allOf(entitas_9.Matcher.Expires));
        }
    }
    exports.ExpiringSystem = ExpiringSystem;
});
define("systems/EntitySpawningTimerSystem", ["require", "exports", "Sdx"], function (require, exports, Sdx_6) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    const T1 = 2; //1 //2
    const T2 = 6; //5 //6
    const T3 = 12; //7 //12
    class EntitySpawningTimerSystem {
        constructor() {
            this.enemyT1 = 0;
            this.enemyT2 = 0;
            this.enemyT3 = 0;
        }
        initialize() {
            // this.enemyT1 = 2.0
            // this.enemyT2 = 6.0
            // this.enemyT3 = 12.0
        }
        execute() {
            this.enemyT1 = this.spawn(this.pool, this.enemyT1, 1);
            this.enemyT2 = this.spawn(this.pool, this.enemyT2, 2);
            this.enemyT3 = this.spawn(this.pool, this.enemyT3, 3);
        }
        spawn(pool, t, enemy) {
            let deltaTime = Sdx_6.Sdx.app.deltaTime;
            const d1 = t - deltaTime;
            if (d1 < 0) {
                switch (enemy) {
                    case 1:
                        pool.createEnemy1();
                        return 1;
                    case 2:
                        pool.createEnemy2();
                        return 5;
                    case 3:
                        pool.createEnemy3();
                        return 7;
                }
            }
            else
                return d1;
        }
        setPool(pool) {
            this.pool = pool;
        }
    }
    exports.EntitySpawningTimerSystem = EntitySpawningTimerSystem;
});
define("systems/ScaleAnimationSystem", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_7, entitas_10) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class ScaleAnimationSystem {
        execute() {
            let delta = Sdx_7.Sdx.app.deltaTime;
            let entities = this.group.getEntities();
            for (let e of entities) {
                let scaleAnimation = e.scaleAnimation;
                if (scaleAnimation.active) {
                    let scale = e.scale;
                    scale.x += scaleAnimation.speed * delta;
                    scale.y = scale.x;
                    if (scale.x > scaleAnimation.max) {
                        scale.x = scaleAnimation.max;
                        scale.y = scale.x;
                        scaleAnimation.active = false;
                    }
                    else if (scale.x < scaleAnimation.min) {
                        scale.x = scaleAnimation.min;
                        scale.y = scale.x;
                        scaleAnimation.active = false;
                    }
                    let sprite = (e.sprite.object);
                    sprite.setScale(scale.x, scale.y);
                }
            }
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_10.Matcher.allOf(entitas_10.Matcher.ScaleAnimation));
        }
    }
    exports.ScaleAnimationSystem = ScaleAnimationSystem;
});
define("systems/RemoveOffscreenShipsSystem", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_8, entitas_11) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class RemoveOffscreenShipsSystem {
        execute() {
            let height = Sdx_8.Sdx.app.height;
            let pool = this.pool;
            let entities = this.group.getEntities();
            for (let e of entities) {
                if (e.position.y > height - e.bounds.radius) {
                    e.isDestroy = true;
                    Sdx_8.Sdx.app.removeSprite(e.sprite.object);
                }
            }
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_11.Matcher.allOf(entitas_11.Matcher.Velocity, entitas_11.Matcher.Position, entitas_11.Matcher.Health, entitas_11.Matcher.Bounds));
        }
    }
    exports.RemoveOffscreenShipsSystem = RemoveOffscreenShipsSystem;
});
define("systems/AddViewSystem", ["require", "exports", "Sdx", "entitas", "Sdx"], function (require, exports, Sdx_9, entitas_12, sdx) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class AddViewSystem {
        constructor() {
            /**
             * OnEntityAdded - Resource component.
             *
             * Load & configure the sprite for this resource component
             *
             * @param group
             * @param e
             * @param index
             * @param component
             */
            this.onEntityAdded = (group, e, index, component) => {
                let sprite = this.atlas.createSprite(e.resource.name, -1);
                let position = e.position;
                sprite.x = position.x;
                sprite.y = position.y;
                if (e.hasScale) {
                    let scale = e.scale;
                    sprite.setScale(scale.x, scale.y);
                }
                sprite.layer = e.layer.ordinal;
                if (e.hasColorAnimation) {
                    sprite.r = e.colorAnimation.redMin;
                    sprite.g = e.colorAnimation.greenMin;
                    sprite.b = e.colorAnimation.blueMin;
                    sprite.a = e.colorAnimation.alphaMin;
                }
                Sdx_9.Sdx.app.addSprite(sprite);
                e.addSprite(sprite.layer, sprite);
            };
            this.atlas = sdx.createAtlas('pack.atlas');
        }
        /**
         * Watch for Resource Added
         *
         * @param pool
         */
        setPool(pool) {
            this.pool = pool;
            pool.getGroup(entitas_12.Matcher.Resource).onEntityAdded.add(this.onEntityAdded);
        }
    }
    exports.AddViewSystem = AddViewSystem;
});
define("systems/DestroySystem", ["require", "exports", "Sdx", "entitas"], function (require, exports, Sdx_10, entitas_13) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    class DestroySystem {
        execute() {
            let entities = this.group.getEntities();
            for (let e of entities) {
                Sdx_10.Sdx.app.removeSprite(e.sprite.object);
                this.pool.destroyEntity(e);
            }
        }
        setPool(pool) {
            this.pool = pool;
            this.group = pool.getGroup(entitas_13.Matcher.allOf(entitas_13.Matcher.Destroy));
        }
    }
    exports.DestroySystem = DestroySystem;
});
define("shmupwarz", ["require", "exports", "Sdx", "entitas", "components", "systems/MovementSystem", "systems/PlayerInputSystem", "systems/SoundEffectSystem", "systems/CollisionSystem", "systems/ExpiringSystem", "systems/EntitySpawningTimerSystem", "systems/ScaleAnimationSystem", "systems/RemoveOffscreenShipsSystem", "systems/AddViewSystem", "systems/DestroySystem", "Sdx"], function (require, exports, Sdx_11, entitas_14, components_1, MovementSystem_1, PlayerInputSystem_1, SoundEffectSystem_1, CollisionSystem_1, ExpiringSystem_1, EntitySpawningTimerSystem_1, ScaleAnimationSystem_1, RemoveOffscreenShipsSystem_1, AddViewSystem_1, DestroySystem_1, Sdx_12) {
    "use strict";
    Object.defineProperty(exports, "__esModule", { value: true });
    var example;
    (function (example) {
        function main() {
            console.log("Hello World");
            console.log(`This is a test ${Sdx_12.sdx_get_version()}`);
            const game = Sdx_11.createGame("ShmupWarz", 640, 720, DATADIR);
            const shmupwarz = new Shmupwarz();
            shmupwarz.start();
            game.profile = true;
            game.start();
            while (game.running) {
                game.handleEvents();
                if (game.getKey(Sdx_11.Input.Keys.Esc))
                    break;
                else {
                    shmupwarz.update(game.deltaTime);
                    game.draw();
                }
            }
        }
        class Shmupwarz {
            start() {
                this.systems = this.createSystems(components_1.Pools.pool);
                this.systems.initialize();
            }
            createSystems(pool) {
                return new entitas_14.Systems()
                    .add(pool.createSystem(MovementSystem_1.MovementSystem))
                    .add(pool.createSystem(PlayerInputSystem_1.PlayerInputSystem))
                    .add(pool.createSystem(SoundEffectSystem_1.SoundEffectSystem))
                    .add(pool.createSystem(CollisionSystem_1.CollisionSystem))
                    .add(pool.createSystem(ExpiringSystem_1.ExpiringSystem))
                    .add(pool.createSystem(EntitySpawningTimerSystem_1.EntitySpawningTimerSystem))
                    .add(pool.createSystem(ScaleAnimationSystem_1.ScaleAnimationSystem))
                    .add(pool.createSystem(RemoveOffscreenShipsSystem_1.RemoveOffscreenShipsSystem))
                    .add(pool.createSystem(AddViewSystem_1.AddViewSystem))
                    .add(pool.createSystem(DestroySystem_1.DestroySystem));
            }
            update(delta) {
                this.systems.execute();
            }
        }
        main();
    })(example || (example = {}));
});
//# sourceMappingURL=game.js.map