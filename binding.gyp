{
  "targets": [
   {
      "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "lib/src"
      ],
      "link_settings": {
      "libraries": [
          "-lSDKDLL",
        ],
        "library_dirs": [
          "./lib",
        ],
      },
      "target_name": "addon",
      "sources": [ "masterkeys.cc" ]
    }
  ]
}