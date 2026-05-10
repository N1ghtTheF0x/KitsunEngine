import { build } from "tsdown"

const PROD = process.argv.includes("prod")

await build({
    entry: ["source/main.ts"],
    target: "esnext",
    platform: "browser",
    format: "esm",
    clean: true,
    define: {
        PROD: JSON.stringify(PROD)
    },
    copy: [
        "public/**/*"
    ],
    sourcemap: !PROD,
    minify: PROD,
    loader: {
        ".frag": "text",
        ".vert": "text"
    },
    deps: {
        alwaysBundle: ["@ntf/logger","@ntf/math"],
        onlyBundle: false
    }
})